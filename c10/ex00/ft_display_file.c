#include "ft_display_file.h"

static ssize_t PutStrInFd(const char *str, size_t fileDescr) {
  ssize_t writedChars = 0;
  if (fileDescr != STDOUT && fileDescr != STDERR) {
    return -1; // Security, we want only write to stdout and stderr
  }
  while (*str)
    writedChars += write(fileDescr, str++, 1);
  writedChars += write(fileDescr, &EOL, 1); // Adds newline
  return writedChars;
}

static int PrintErr(errCode_t err) {
  int toRet = (int)err;  
  if (err != Ok) {
    if (PutStrInFd(errString[err], STDERR)) {}
  }
  return toRet;  
}

static void print_buffer(void *p_buf, int size) {  
  int nb_chunks = size / CHUNK_SIZE;
  int size_last_chunk = size % CHUNK_SIZE;
  while (nb_chunks) {
    write(STDOUT, p_buf, CHUNK_SIZE);
    p_buf += CHUNK_SIZE;
    -- nb_chunks;
  }
  while(size_last_chunk) {
    write(STDOUT, p_buf, 1);
    ++ p_buf;
    -- size_last_chunk;
  }
}

int main(int argc, char **argv) {
  char buffer[BUFFERSIZE];
  void *p_buf = (void *)buffer;
  int bytes_read;
  if (argc == 1)
    return PrintErr(NoArgs);
  if (argc > 2)
    return PrintErr(TooManyArgs);
  int fd = open((const char *)argv[1], O_RDONLY);
  if (fd == -1) {
    return PrintErr(CantRead);
  }
  while((bytes_read = read(fd, p_buf, BUFFERSIZE))) {
    if (bytes_read == -1) {
      return PrintErr(CantRead);
    }
    print_buffer(p_buf, bytes_read);
  }
  return close(fd);
}
