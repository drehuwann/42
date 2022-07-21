#include "./protos.h"

#include <unistd.h>
#include <stdlib.h>

#define INT_MIN -2147483648
#define INT_MAX 2147483647

const char EOL = '\n';
const char space = 0x20;

int intTab[16] = {
    INT_MIN, -1, 0, 42,
    88, INT_MAX, -42, 3,
    14, 0, 16, 32,
    123456, 7890, -98765, -43210};

int is_printable(char *str)
{
  char c;
  while((c = *str ++) != '\0')
    if ( ( c < ' ' ) || ( c > '~' ) )
      return 0;
  return 1;
}

void pf_test42(int i)
{
  if ( i == 42 ) {
    if (write(1, "Y", 1)) {}
  } else {
    if (write(1, "N", 1)) {}
  }
  if (write(1, "\n", 1)) {}
}

void ft_putnbr(int nb)
{
  if (nb == 0)
  {
    if (write(1, "0", 1) && write(1, &space, 1)) {}
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
  if (negative) write(1, "-", 1);
  while (pRevStr != debutRevStr)
  {
    pRevStr--;
    if (write(1, pRevStr, 1)) {}
  }
  if (write(1, &space, 1)) {}
}

int isEven(int n) {
    return ((n % 2) == 0);
}

int minus(int a, int b) {
  return (a - b);
}

void eol() {
  if(write(1, &EOL, 1)) {}
}

int main(int argc, char **argv) {
  ft_foreach(intTab, 16, ft_putnbr);
  eol();
  int *retTab = ft_map(intTab, (int)(sizeof(intTab) / sizeof(int)), isEven);
  ft_foreach(retTab, 16, ft_putnbr);
  eol();
  if (retTab) {
    free(retTab);
    retTab = NULL;
  }
  pf_test42(41 + ft_any(argv, is_printable));
  pf_test42(42 + ft_any(&(argv[1]), is_printable));
  const char s1[3] = "42";
  const char s2[3] = "\5\4";
  const char s3[2] = "\005";
  const char s4[2] = "\010";
  const char s5[9] = "k-rent-2";
  const char *strTab[5];
  strTab[0] = s1;
  strTab[1] = s2;
  strTab[2] = s3;
  strTab[3] = s4;
  strTab[4] = s5;
  pf_test42(40 + ft_count_if((char **)strTab, 5, is_printable));
  pf_test42(42 + ft_is_sort(intTab, 16, minus));
  unsigned int it = 0;
  while (it < 16) {
    intTab[it] = 42;
    ++it;
  }
  pf_test42(41 + ft_is_sort(intTab, 16, minus));
  intTab[0] = -64;
  intTab[1] = -64;
  intTab[2] = -11;
  intTab[3] = 11;
  intTab[4] = 18;
  intTab[5] = 24;
  intTab[6] = 41;
  intTab[11] = 64;
  intTab[12] = 150;
  intTab[13] = 150;
  intTab[14] = 153;
  intTab[15] = 164;
  pf_test42(41 + ft_is_sort(intTab, 16, minus));
  return argc;
}
