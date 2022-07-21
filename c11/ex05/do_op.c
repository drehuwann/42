#include <unistd.h>

#define INT_MIN -2147483648
#define INT_MAX 2147483647

const char eol = '\n';

static void pf_putnbr(int nb)
{
  if (nb == 0)
  {
    write(1, "0", 1);
    return;
  }
  int negative = (nb < 0); // negative=0 -> positive; negative=1 -> negative
  char reste = 0;
  char reversedStr[11] = "8463847412"; //stores (string)nb from right to left
  // default value is INT_MIN
  char *debutRevStr = &reversedStr[0];
  char *pRevStr = debutRevStr;

  if ( nb == INT_MIN )
  {
    // Keeps default reversedStr => INT_MIN
    pRevStr = &reversedStr[10];
  }
  else
  {
    if ( negative )
      nb *= -1;
    while ( nb != 0 )
    {
      reste = nb % 10;
      nb /= 10;
      char c = (char)('0' + reste);
      *pRevStr = c;
      pRevStr++;
    }
  }
  *pRevStr = '\0'; //null-terminates str
  if (negative && write(1, "-", 1)) {}
  while (pRevStr != debutRevStr)
  {
    pRevStr--;
    if (write(1, pRevStr, 1)) {}
  }
  if (write(1, &eol, 1)) {}
}

typedef enum {
  addi,
  subs,
  divi,
  mult,
  modu,
  noop
} operator;

static operator pf_op(const char *opStr) {
  char c = opStr[0];
  if (opStr[1]) return noop;
  if (c == '+') return addi;
  if (c == '-') return subs;
  if (c == '/') return divi; 
  if (c == '*') return mult; 
  if (c == '%') return modu;
  return noop;
}

static ssize_t pf_print(const char *str) {
  ssize_t toRet = 0;
  const char eol = '\n';
  char c = 0;
  while ((c = *str) != 0) {
    toRet += write(1, &c, 1);
    ++str;
  }
  toRet += write(1, &eol, 1);
  return toRet;
}

static void add(int a, int b) {
  pf_putnbr(a + b);
}

static void sub(int a, int b) {
  pf_putnbr(a - b);
}

static void div(int a, int b) {
  if (b) {
    pf_putnbr(a / b);
  } else {
    if (pf_print("Stop : division by zero")) {}
  }
}

static void mul(int a, int b) {
  pf_putnbr(a * b);
}

static void mod(int a, int b) {
  if (b) {
    pf_putnbr(a % b);
  } else {
    if (pf_print("Stop : modulo by zero")) {}
  }
}

static int str2int(const char *str) {
  int toRet = 0;
  char c = 0;
  int minusCnt = 0;
  while((c = *str) != 0) {
    if (c >= '0' && c <= '9') {
      toRet *= 10;
      toRet += (c - '0');
    } else if (c == '-') {
      ++ minusCnt;
    } else if (c == '+') {
    } else {
      break;
    }
    ++ str;
  }
  minusCnt %= 2;
  if (minusCnt)
    toRet *= -1;
  return toRet;
}

static void (*tabOp[5])(int, int) = {add, sub, div, mul, mod};

int main(int argc, const char **argv) {
  if (argc != 4) {
    return -1;
  }
  operator op = pf_op(argv[2]);
  if (op == noop) {
    return (pf_print("0") - 3);
  }
  tabOp[op](str2int(argv[1]), str2int(argv[3]));
  return 0;
}
