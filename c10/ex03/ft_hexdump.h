#ifndef _FT_HEXDUMP_H_
#define _FT_HEXDUMP_H_

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>
#include <stdlib.h>

#define STDIN STDIN_FILENO
#define STDOUT STDOUT_FILENO
#define STDERR STDERR_FILENO

#define CHUNK_SIZE __SIZEOF_POINTER__    // 4 on x86; 8 on x86_64
#define BUF_SIZE 512

const char pipeChar = '|';
const char dot = '.';
const char EOL = '\n';
const char star = '*';
const char space = 0x20;

const size_t bytesPerLine = 16;

typedef enum options {
  none = 0b00000000,
  canonical = 0b00000001
} opts;

#endif  // _FT_HEXDUMP_H_
