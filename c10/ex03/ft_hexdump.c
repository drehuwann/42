#include <ft_hexdump.h>

///@brief computes and returns length of null terminated string
static int pf_len(const char *str) {
  int toRet = 0;
  while (*str) {
    ++ toRet;
    ++ str;
  }
  return toRet;
}

///@brief puts n times c in fd
static void pf_putChars(int fd, const char *c, unsigned int n) {
  while(n) {
    --n;
    if (write(fd, c, 1)) {}
  }
}

///@brief computes and print full error string.
static int Err(int errCode, const char *processName, const char *processedArg) {
  const char *errnoStr = (const char *)strerror(errCode);
  if (write(STDERR, processName, pf_len(processName)) &&
    write(STDERR, ": ", 2) &&
    write (STDERR, processedArg, pf_len(processedArg)) &&
    write(STDERR, ": ", 2) &&
    write(STDERR, errnoStr, pf_len(errnoStr)) &&
    write(STDERR, &EOL, 1)) {}
  return errCode;
}

///@brief suppress and returns first item from *p_argv
static char *pf_popParam(char **p_argv) {
  if (p_argv == NULL) return NULL;
  char **argv = p_argv;
  char *toRet = argv[0];
  while (argv[1]) {
    argv[0] = argv[1];
    ++ argv;
  }
  *argv = NULL;
  return toRet;
}

/*! @brief transforms argc and argv in valid files list, computing total valid
 * files length.
 * @return last errno */
static int parseArgs(int *p_argc, char ***p_argv, char *optionsFlag,
    size_t *size) {
  int lastErrCode = 0;
  int fd = -1;
  char p_buf[BUF_SIZE];
  if (!p_argc || !p_argv) {
    return Err(EINVAL, "ft_hexdump", "parseArgs(int *, char ***");
  }
  int argc = *p_argc;
  char **argv = *p_argv;
  if (argc == 0) {
    return Err(EINVAL, "ft_hexdump", "parseArgs(&(0), char ***)");
  }
  if (argc == 1) {
    return Err(ENOSYS, "ft_hexdump", "redirection");
  }
  ssize_t bytesRead = 0;
  while (argc - 1) {
    --argc;
    if (*(argv[argc]) == '-') {
      if ((*((argv[argc]) + 1) == 'C') && (*(argv[argc] + 2) == '\0')) {
        *optionsFlag |= (char)canonical;
      } else if (*((argv[argc]) + 1) == '\0') {
        lastErrCode = Err(ENOSYS, (const char *)basename(argv[0]),
          "redirection");
      } else {
        lastErrCode = Err(EINVAL, (const char *)basename(argv[0]),
          (const char *)pf_popParam(&(argv[argc])));
      }
      if (pf_popParam(&(argv[argc]))) {
        -- (*p_argc);
      }
    } else {
      fd = open((const char *)argv[argc], O_RDONLY);
      if (fd == -1) {
        lastErrCode = Err(errno, (const char *)basename(argv[0]),
          (const char *)pf_popParam(&(argv[argc])));
        (*p_argc) --;
      } else if (fd == STDIN || fd == STDOUT || fd == STDERR) {
        lastErrCode = Err(ENOSYS, (const char *)basename(argv[0]),
          "redirection");
        if (pf_popParam(&(argv[argc]))) {}
        (*p_argc) --;
      } else {
        // file is valid. Measure and Close it.
        while ((bytesRead = read(fd, p_buf, BUF_SIZE))) {
          if (bytesRead == -1) {
            lastErrCode = Err(errno, "ParseArgs", "read bytes");
            break;
          }
          *size += bytesRead;
        }
        if (close(fd)) {}
      }
    }
  }
  return lastErrCode;
}

/// @brief returns a digit c in hex. if c >= 16, returns '?'. 
static char pf_Hex(unsigned char c)
{
  if ( c <= 9 )
    c += '0';
  else if ( c <= 15 )
    c += 'W'; // 'W' is 'a' - 10
  else //Error : c >= 16
    c = '?';
  return c;
}

/// @brief display number in hex, using nb_digits digits.
static void pf_printHex(unsigned int number, unsigned int nb_digits) {
  int index = nb_digits;
  char toPrint[index];
  while (index >= 0) {
    -- index;
    toPrint[index] = pf_Hex(number % 16);
    number /= 16;
  }
  if (write(STDOUT, &toPrint, nb_digits)) {}
}

/*! @brief replace in p_line unprintable chars by dots('.'), and prints the \
 * result between two pipes('|') */
static void printCanonical(const char *p_line, size_t size) {
  size_t index = 0;
  char c = 0;
  if (write(STDOUT, &pipeChar, 1)) {}
  while(index < size) {
    c = p_line[index];
    if ((c < 0x20) || (c > 0x7e))
      c = dot;
    if (write(STDOUT, &c, 1)) {}
    ++ index;
  }
  if (write(STDOUT, &pipeChar, 1)) {}
}

/*! @brief displays size bytes of *p_line, according to optionsFlag. \
 * If size = 0 or size > bytesperline(16), sets size = bytesperline. */
static void print_line(unsigned int offset, const char *p_line, size_t size,
    const char optionsFlag) {
  pf_printHex(offset, 7 + (optionsFlag & canonical));
  pf_putChars(STDOUT, &space, 1 + (optionsFlag & canonical));
  if (size == 0 || size > bytesPerLine)
    size = bytesPerLine;
  size_t index = 0;
  if (optionsFlag & canonical) {
    while (index < bytesPerLine) {
      if (index < size) {
        pf_printHex(p_line[index], 2);
      } else {
        pf_putChars(STDOUT, &space, 2);
      }
      ++ index;
      if (write(STDOUT, &space, 1)) {}
      if ((index % (bytesPerLine / 2) == 0) && write(STDOUT, &space, 1)) {}
    }
    printCanonical(p_line, size);
  } else {
    while (index < bytesPerLine) {
      if (index < size) {
        pf_printHex(0x100 * (index == size - 1 ? 0 : p_line[index + 1])
          + p_line[index], 4);
      } else {
        pf_putChars(STDOUT, &space, 4);
      }
      index += 2;
      if ((index < bytesPerLine) && write(STDOUT, &space, 1)) {}
    }
  }
  if (write(STDOUT, &EOL, 1)) {}
}

///@brief mimics POSIX memcmp
static short pf_memcmp(const void *s1, const void *s2, size_t n) {
  size_t nbShorts = n / 2;
  size_t lastShort = n % 2;
  short toRet = 0;
  while (nbShorts) {
    toRet += *(short *)s1 - *(short *)s2;
    s1 += sizeof(short);
    s2 += sizeof(short);
    -- nbShorts;
  }
  while (lastShort) {
    toRet += *(char *)s1 - *(char *)s2;
    ++s1;
    ++s2;
    -- lastShort;
  }
  return toRet;
}

///@brief mimics POSIX memcpy
static void *pf_memcpy(void *dest, const void *srce, size_t n) {
  if (srce == NULL || dest == NULL || n == 0)
    return dest;
  void *toRet = dest;
  size_t nb_chunks = n / CHUNK_SIZE;
  size_t size_last_chunk = n % CHUNK_SIZE;
  // assuming CHUNK_SIZE = size of pointer.
  void *chunk_dst = dest;
  const void *chunk_src = srce;
  while (nb_chunks) {
    if (sizeof(long) != CHUNK_SIZE) { // LLP64 data model
      *((long long *)chunk_dst) = *((long long *)chunk_src);
    } else {
      *((long *)chunk_dst) = *((long *)chunk_src);
    }
    chunk_dst += CHUNK_SIZE;
    chunk_src += CHUNK_SIZE;
    -- nb_chunks;
  }
  char *dst = (char *)chunk_dst;
  const char *src = (const char *)chunk_src;
  while(size_last_chunk) {
    *dst = *src;
    ++ dst;
    ++ src;
    -- size_last_chunk;
  }
  return toRet;
}

/// @brief displays size bytes from buffer *p_buf, according to optionsFlag
static void print_buffer(const char *p_buf, size_t size,
    const char optionsFlag) {
  static unsigned int offset = 0;
  const int chunksPerLine = bytesPerLine / CHUNK_SIZE;
  int nb_chunks = size / CHUNK_SIZE;
  int size_last_chunk = size % CHUNK_SIZE;
  char line[bytesPerLine];
  char lastLine[bytesPerLine];
  int index = 0;
  int isFirstLine = 1;
  int starPrinted = 0;
  while (nb_chunks) {
    if (! pf_memcpy((char *)(line) + index * CHUNK_SIZE, p_buf, CHUNK_SIZE) &&
        Err(errno, "print_buffer", "pf_memcpy")) {
      return;
    }
    ++ index;
    p_buf += CHUNK_SIZE;
    -- nb_chunks;
    offset += CHUNK_SIZE;
    if (index == chunksPerLine) {
      if (isFirstLine || (! isFirstLine && pf_memcmp((const void*)line,
          (const void *)lastLine, bytesPerLine)) != 0) {
        print_line(offset - bytesPerLine, line, bytesPerLine, optionsFlag);
        starPrinted = 0;
        if (isFirstLine)
          isFirstLine = 0;
        if (! pf_memcpy(lastLine, line, bytesPerLine)
            && Err(errno, "print_buffer", "pf_memcpy")) {
          return;
        }
      } else {
        if ((! starPrinted) && write(STDOUT, &star, 1)) {
          if (write(STDOUT, &EOL, 1)) {}
          starPrinted = 1;
        }
      }
      index = 0;
    }
  }
  if(size_last_chunk) {
    if (! pf_memcpy((char *)(line) + index * CHUNK_SIZE, p_buf, size_last_chunk)
        && Err(errno, "print_buffer", "pf_memcpy")) {
      return;
    }
    print_line(offset - (offset % bytesPerLine), line,
      index * CHUNK_SIZE + size_last_chunk, optionsFlag);
    offset += size_last_chunk;
  }
  pf_printHex(offset, 7 + (optionsFlag & canonical));
  if (write(STDOUT, &EOL, 1)) {}
}

///@brief exits 0 on success and >0(errno) if an error occured
int main(int argc, char **argv) {
  char optionsFlag = (char)none;
  size_t size = 0;
  char *buffer = NULL;
  int errCode = parseArgs(&argc, &argv, &optionsFlag, &size);
  buffer = (char *)malloc(sizeof(char) * size);
  if (!buffer) return Err(errno, (const char *)basename(argv[0]), "");
  void *p_buf = (void *)buffer;
  ssize_t bytes_read = 0;
  int fd = -1;
  int index = 1;
  size_t totalSize = 0;
  while (index < argc) {
    fd = open(argv[index], O_RDONLY);
    while((bytes_read = read(fd, p_buf, size - totalSize))) {
      if (bytes_read == -1) {
        errCode = Err(errno, (const char *)basename(argv[0]), "read Bytes");
      } else {
        totalSize += (size_t)bytes_read;
        p_buf = &(buffer[totalSize]);
      }
    }
    if ((close(fd) == -1) && Err(errno, (const char *)basename(argv[0]),
      (const char *)basename(argv[index]))) {}
    ++ index;
  }
  p_buf = &(buffer[0]);
  print_buffer((const char *)p_buf, totalSize, (const char)optionsFlag);
  if (buffer) {
    free(buffer);
    buffer = NULL;
  }
  return errCode;
}
