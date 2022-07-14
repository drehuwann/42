#include <ft_tail.h>

static int pf_len(const char *str) {
  int toRet = 0;
  while (*str) {
    ++ toRet;
    ++ str;
  }
  return toRet;
}

static int pf_digit(const char *str, int *hasPlus) {
  // returns -1=false, else return digit
  int toRet = 0;
  *hasPlus = 0;
  if (*str == '+') {
    *hasPlus = 1;
    ++str;
    if (! str)
      return -1;
  }
  while (*str) {
    toRet *= 10;
    if (*str < '0' || *str > '9')
      return -1;
    toRet = toRet + (*str - '0');
    ++str;
  }
  return toRet;
}

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

static int Err(int errCode, const char *processName, const char *processedArg) {
  if (write(STDERR, &"Error in ", 9)) {}
  if (write(STDERR, processName, pf_len(processName))) {}
  if (write(STDERR, &", processing ", 14)) {}
  if (write(STDERR, processedArg, pf_len(processedArg))) {}
  if (write(STDERR, &" : ", 3)) {}
  if (write(STDERR, (const char *)strerror(errCode),
    pf_len(strerror(errCode)))) {}
  if (write(STDERR, &"\n", 1)) {}
  return errCode;
}

static void print_buffer(void *p_buf, size_t size) {  
  size_t nb_chunks = size / CHUNK_SIZE;
  size_t size_last_chunk = size % CHUNK_SIZE;
  while (nb_chunks) {
    if (write(STDOUT, p_buf, CHUNK_SIZE)) {}
    p_buf += CHUNK_SIZE;
    -- nb_chunks;
  }
  while(size_last_chunk) {
    if (write(STDOUT, p_buf, 1)) {}
    ++ p_buf;
    -- size_last_chunk;
  }
}

static file_info ParseFile(const char *filename) {
  file_info toRet = fi_default; // toRet default value. returned if fd==STDIN
  int fd = STDIN;
  int fileSize = 0;
  int newLines = 0;
  char byteRead[1];
  if (filename) {
    if ((fd = open(filename, O_RDONLY)) == -1) {
      return fi_fault;
    }
  } else {
    fd = STDIN;
    return toRet;
  }
  while (read(fd, byteRead, 1)) {
    ++ fileSize;
    if (byteRead[0] == '\n')
      ++newLines;
  }
  if (byteRead[0] != '\n') {
    ++ newLines;  // if last byte is not EOL, consider EOF as EOL
  }
  toRet.newlineCount = newLines;
  toRet.posEOF = fileSize;
  if (fd != STDIN)
    close(fd);
  return toRet;
}

static void shiftLeftByteBuf(fifo_byte_buffer *fbb) {
  size_t it = 0;
  while (it < fbb->size - 1) {
    (fbb->bytes)[it] = (fbb->bytes)[it + 1];
    ++it;
  }
}

static void shiftLeftLineBuffer(fifo_line_buffer *flb) {
  size_t it = 0;
  if (flb) {
    if (flb[0]->bytes) {
      free(flb[0]->bytes);
      flb[0]->bytes = NULL;
      flb[0]->size = 0;
    }
    free(flb[0]);
    while (flb[it + 1] != NULL) {
      flb[it] = flb[it + 1];
      ++ it;
    }
    flb[it] = NULL;
  } else {
    if (Err(EFAULT, "shiftLeftLineBuffer", "buffer doesn't exist")) {}
  }
}

///@brief if size = 0, parses until '/n'
static fifo_byte_buffer *ParseIntoFifoByteBuf(int fd, size_t size) {
  char byteRead;
  ssize_t readReturn;
  size_t it;
  fifo_byte_buffer *toRet = (fifo_byte_buffer *)malloc(sizeof(
    fifo_byte_buffer));
  toRet->bytes = NULL;
  toRet->size = 0;
  if (size != 0) {
    toRet->bytes = (char *)(malloc(size * sizeof(char)));
    it = 0;
    while (it < size) {
      readReturn = read(fd, (void *)&byteRead, 1);
      if (readReturn == -1) {
        if (Err(errno, "ParseIntoFifoByteBuf", "readByte")) {}
        if (toRet) {
          if (toRet->bytes) {
            free(toRet->bytes);
            toRet->bytes = NULL;
            toRet->size = 0;
          }
          free(toRet);
          toRet = NULL;
        }
        return (fifo_byte_buffer *)(&fbb_fault);
      } else {
        if (readReturn == 0) {
          //we catched EOF before reaching size
          toRet->size = it + 1;
          return toRet;
        }
        toRet->bytes[it] = byteRead;
        ++ it;
      }
    }
    // now allocated toRet is full ... so shift it until EOF
    toRet->size = size;
    while (read(fd, (void *)&byteRead, 1)) {
      shiftLeftByteBuf(toRet);
      (toRet->bytes)[size - 1] = byteRead;
    }
  } else {
    // we have expressely passed size = 0 to the function, so extract '\n'
    // delimited line ...
    byteRead = '\0';
    readReturn = read(fd, (void *)&byteRead, 1);
    it = 0;
    char *bytePtr = NULL;  // used in next while
    char *oldBytePtr = NULL;  // used in next while
    while (byteRead != '\n') {
      if (readReturn == -1) {
        if (Err(errno, "ParseIntoFifoByteBuf", "readLine")) {}
        if (toRet) {
          if (toRet->bytes) {
            free(toRet->bytes);
            toRet->bytes = NULL;
            toRet->size = 0;
          }
          free(toRet);
          toRet = NULL;
        }
        return (fifo_byte_buffer *)(&fbb_fault);
      } else {
        if (readReturn == 0) {  // we catched EOF before reaching EOL
          if (bytePtr) {
            free(bytePtr);
            bytePtr = NULL;
          }
          if (oldBytePtr == NULL) {
            // there is nothing in this last line before EOF. Returns NULL.
            if (toRet) {
              if (toRet->bytes) {
                free(toRet->bytes);
                toRet->bytes = NULL;
                toRet->size = 0;
              }
              free(toRet);
              toRet = NULL;
            }
            return toRet;
          }
          toRet->bytes = oldBytePtr;
          return toRet;
        }
        bytePtr = (char *)malloc((it + 1) * sizeof(char));
        if (oldBytePtr) {
          bytePtr = pf_memcpy((void *)bytePtr, (const void *)oldBytePtr, it);
          free(oldBytePtr);
          oldBytePtr = NULL;
        }
        bytePtr[it] = byteRead;
        ++ it;
        toRet->size = it;
        toRet->bytes = bytePtr;
        oldBytePtr = (char *)malloc(it * sizeof(char));
        if (bytePtr) {
          oldBytePtr = pf_memcpy((void *)oldBytePtr, (const void *)bytePtr, it);
          free(bytePtr);
          bytePtr = NULL;
        }
        readReturn = read(fd, (void *)&byteRead, 1);
        if (byteRead == '\n') {  // we will quit this loop so update toRet.
          toRet->bytes = oldBytePtr;
          if (bytePtr) {
            free(bytePtr);
            bytePtr = NULL;
          }
        }
      }
    }
  }
  return toRet;
}

static void lineSeek(int fd, int count) {
  char carac[1];
  if (count < 0)
    count = 0;
  while(count) {
    if(read(fd, carac, 1) == -1) {
      if (Err(errno, "lineSeek", "read")) {}
      return;
    }
    if (*carac == '\n')
      -- count;
  }
}

static void byteSeek(int fd, int offset) {
  char bufChunk[CHUNK_SIZE];
  char carac[1];
  if (offset < 0)
    offset = 0;
  int numChunks = offset / CHUNK_SIZE;
  int lastChunkSize = offset % CHUNK_SIZE;
  while (numChunks) {
    if (read(fd, (char *)bufChunk, sizeof(bufChunk)) == -1) {
      if (Err(errno, "byteSeek", "read")) {}
      return;
    }
    -- numChunks;
  }
  while (lastChunkSize) {
    if (read(fd, (char *)carac, 1) == -1) {
      if (Err(errno, "fileSeek", "read")) {}
      return;
    }
    -- lastChunkSize;
  }
}

int main(int argc, char **argv) {
  int bytes_read;
  int fd;
  file_info f_inf;
  atom atomType = line;  // the default
  int atomsCount = DEFAULT_KEEPED_ATOM;
  int hasPlus = 0; // for false; 1=true
  fifo_line_buffer *fifoBufLines = NULL;

  char **file_list = (char **)malloc((argc + 1) * sizeof(*file_list));
  // allocated one more to eventually replace void by "-"
  int index = 1;
  char *fileName;
  int fileListIndex = 0;
  while ((fileName = argv[index]) != NULL) {
    if (*fileName == '-' && *(fileName + 1) == 'c'
        && *(fileName + 2) == '\0') { // valid -c switch
      atomType = byte;
      ++ index;
      if (argv[index]) {
        atomsCount = pf_digit((const char *)(argv[index]), &hasPlus);
      } else {
        atomsCount = -1;
      }
      if (atomsCount == -1) {
        if (Err(EINVAL, (const char *)basename(argv[0]), "-c switch.")) {}
        if (write(STDOUT, "Keeping default value\n", 22)) {}
        atomsCount = DEFAULT_KEEPED_ATOM;
      } else {
        ++ index;
      }
    } else {
      file_list[fileListIndex] = argv[index];
      ++ index;
      ++ fileListIndex;
    }
  }
  file_list[fileListIndex] = NULL; // null terminates list.
  
  char p_buf[BUF_SIZE];
  
  if (file_list[0] == NULL) {  // if no files set file[0] to "-"
    file_list[0] = (char*)dash;
    file_list[1] = NULL;
  }

  index = 0;
  while ((fileName = file_list[index]) != NULL) {
    if ((*fileName == '-') && (*(fileName + 1) == '\0')) {
      fd = STDIN;
      if (atomType == line) {
        fifoBufLines = (fifo_line_buffer *)malloc(
          (atomsCount + 1) * sizeof(fifo_line_buffer));
        size_t it = 0;
        while ((int)it < atomsCount) {
          fifoBufLines[it] = ParseIntoFifoByteBuf(fd, 0);
          ++ it;
        }
        fifoBufLines[atomsCount] = NULL;
        fifo_byte_buffer *nextbb = NULL;
        while ((nextbb = ParseIntoFifoByteBuf(fd, 0)) != NULL) {
          shiftLeftLineBuffer(fifoBufLines);
          fifoBufLines[atomsCount - 1] = nextbb;  
        }
      } else {  // atomType = byte
        if (hasPlus) {
          if (Err(EINVAL, (const char *)basename(argv[0]),
            " '+' switch not implemented for stdin.")) {}
          if (write(STDERR, "Ignoring '+' switch.", 21)) {}
        }
        fifoBufLines = (fifo_line_buffer *)malloc(2 * sizeof(fifo_line_buffer));
        fifoBufLines[0] = ParseIntoFifoByteBuf(fd, atomsCount);
        fifoBufLines[1] = NULL;
      }
    } else {
      f_inf = ParseFile((const char *)fileName);
      fd = open((const char *)fileName, O_RDONLY);
    }

    if (fd == -1) {
      if (Err(errno, (const char *)basename(argv[0]),
        (const char*)basename(fileName))) {}
    } else {
      if (file_list[1] != NULL) {
        if (index > 0 && write(STDOUT, &EOL,1)) {}
        if (write(STDOUT, &headerBeg, sizeof(headerBeg))) {}
      }
      if (fd != STDIN && fd != STDOUT && fd != STDERR) {

        if (file_list[1] != NULL) {
          if (write(STDOUT, (const void *)fileName,
            pf_len((const char *)fileName))) {}
          if (write(STDOUT, &headerEnd, sizeof(headerEnd))) {}
        }

        if (atomType == byte) {
          if (hasPlus == 1) {
            byteSeek(fd, atomsCount);
          } else {
            byteSeek(fd, f_inf.posEOF - atomsCount);
          }
        } else {
          if (atomType == line) {
            lineSeek(fd, f_inf.newlineCount - atomsCount);
          }
        }
        while((bytes_read = read(fd, p_buf, sizeof(p_buf)))) {
          if (bytes_read == -1) {
            if (Err(errno, (const char *)basename(argv[0]),
              (const char*)basename(fileName))) {}
            break;
          } else {
            print_buffer(p_buf, bytes_read);
          }
        }
      } else {
        if (file_list[1] != NULL) {
          if (write(STDOUT, "standard input", 14)) {}
          if (write(STDOUT, &headerEnd, sizeof(headerEnd))) {}
        }
        // Now we can output fifoBufLines into STDOUT.
        fifo_line_buffer *start_flb = fifoBufLines;
        while( *fifoBufLines ) {
          size_t lineSize = (*fifoBufLines)->size;
          print_buffer((*fifoBufLines)->bytes, lineSize);
          free ((*fifoBufLines)->bytes);
          free(*fifoBufLines);
          ++ fifoBufLines;
          if (*fifoBufLines && write(STDOUT, &EOL, 1)) {}
        }
        if (start_flb) {
          free(start_flb);
          start_flb = NULL;
        }
      }
    }

    if (close(fd) == -1) {
      if (Err(errno, (const char *)basename(argv[0]),
        (const char *)basename(fileName))) {}
    }
    ++ index;
  }
  index = 0;
  
  if (file_list) {
    free(file_list);
    file_list = NULL;
  }
}
