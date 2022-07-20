#ifndef _FT_TAIL_H_
#define _FT_TAIL_H_

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>
#include <stdlib.h>

#define STDIN   STDIN_FILENO
#define STDOUT  STDOUT_FILENO
#define STDERR  STDERR_FILENO

#define CHUNK_SIZE __SIZEOF_POINTER__    // 4 on x86; 8 on x86_64
#define BUF_SIZE 512
#define DEFAULT_KEEPED_ATOM 10

const char EOL = '\n';
const char headerBeg[4] = {'=', '=', '>', ' '};
const char headerEnd[5] = {' ', '<', '=', '=', EOL};
const char dash[2] = "-";

typedef enum {
  byte,
  line
} atom;

typedef struct {
  int posEOF;
  int newlineCount;
} file_info;

const file_info fi_default = {0, 0};
const file_info fi_fault ={-1, -1};

typedef struct {
  char *bytes;
  size_t size;
} fifo_byte_buffer;

const fifo_byte_buffer fbb_fault = {NULL, 0};

///@brief null-terminated array of byte_buffers 
typedef fifo_byte_buffer *fifo_line_buffer;

#endif  // _FT_TAIL_H_
