#ifndef _FT_DISPLAY_FILE_H_
#define _FT_DISPLAY_FILE_H_

#include <unistd.h>
#include <fcntl.h>

#define STDOUT STDOUT_FILENO
#define STDERR STDERR_FILENO

#define CHUNK_SIZE __SIZEOF_POINTER__    // 4 on x86; 8 on x86_64
#define BUFFERSIZE 512

typedef enum {
  Ok,
  NoArgs,
  TooManyArgs,
  CantRead  
} errCode_t;

const char *errString[] = {
  "",
  "File name missing.",
  "Too many arguments.",
  "Cannot read file."
};

const char EOL = '\n';

#endif  // _FT_DISPLAY_FILE_H_
