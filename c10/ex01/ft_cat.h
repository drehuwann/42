#ifndef _FT_CAT_H_
#define _FT_CAT_H_

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

#define STDIN   STDIN_FILENO
#define STDOUT  STDOUT_FILENO
#define STDERR  STDERR_FILENO

#define CHUNK_SIZE __SIZEOF_POINTER__    // 4 on x86; 8 on x86_64

#ifndef BUFFERSIZE
// define BUFFERSIZE in Makefile : regulate using ulimit -Ss 30
#define BUFFERSIZE 512
#endif

const char EOL = '\n';

#endif  // _FT_CAT_H_
