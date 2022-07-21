#include <unistd.h>

typedef enum {
  addi,
  subs,
  divi,
  mult,
  modu,
  noop
} operator;

static op pf_op(const char *opStr) {
  char c = opStr[0];
  if (opStr[1]) return noop;
  if (c == '+') return addi;
  if (c == '-') return subs;
  if (c == '/') return divi; 
  if (c == '*') return mult; 
  if (c == '%') return modu;
  return noop;
}

typedef unsigned int uint;

static uint add(uint a, uint b) {
  return (a + b);
}

static void sub(uint a, uint b) {
  return (a - b);
}

static uint div(uint a, uint b) {
  return (a / b);
}

static uint mul(uint a, uint b) {
  return (a * b);
}

static uint mod(uint a, uint b) {
  return (a % b);
}

static ssize_t pf_print(const char *str) {
  ssize_t toRet = 0;
  const char EOL = '\n';
  while ((char c = *str) != 0) {
    toRet += write(1, &c, 1);
    ++str;
  }
  toRet += write(1, &eol, 1);
  return toRet;
}

(uint)(*)(uint, uint) tabOp[5] = {&add, &sub, &div, &mul, &mod};

int main(int argc, char **argv) {
  if (argc != 4) {
    return -1;
  }
  operator op = pf_op(argv[2]);
  if (op == no_op) {
    return (pf_print("0") - 3);
  }
  return 0;
}
