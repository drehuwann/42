#include <ft_cat.h>

static int pf_len(const char *str) {
  int toRet = 0;
  while (*str) {
    ++ toRet;
    ++ str;
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

static void print_buffer(void *p_buf, int size) {  
  int nb_chunks = size / CHUNK_SIZE;
  int size_last_chunk = size % CHUNK_SIZE;
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

int main(int argc, char **argv) {
  char buffer[BUFFERSIZE]; // BUFFERSIZE should be defined in MakeFile
  void *p_buf = (void *)buffer;
  int bytes_read;
  int fd;
  int args_to_process;
  if (argc == 1) {  // if no args set arg[1] to "-"
    argc = 2;
    argv[1] = "-";
  }
  args_to_process = argc - 1;
  while (args_to_process) {
    if ((*(argv[argc - args_to_process]) == '-')
        && (*(argv[argc - args_to_process] + 1) == '\0')) {
      fd = STDIN;
    } else {
      fd = open((const char *)argv[argc - args_to_process], O_RDONLY);
    }
    if (fd == -1) {
      return Err(errno, (const char *)basename(argv[0]),
        (const char*)basename(argv[argc - args_to_process]));
    }
    while((bytes_read = read(fd, p_buf, BUFFERSIZE))) {
      if (bytes_read == -1) {
        return Err(errno, (const char *)basename(argv[0]),
          (const char*)basename(argv[argc - args_to_process]));
      }
      print_buffer(p_buf, bytes_read);
    }
    if (close(fd) == -1) {
      return Err(errno, (const char *)basename(argv[0]),
        (const char *)basename(argv[argc - args_to_process]));
    }
    -- args_to_process;
  }  
}
