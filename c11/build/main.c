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

static ssize_t pf_len(const char *str) {
  ssize_t toRet = 0;
  if (!str) return -1;
  while(*str) {
    ++ toRet;
    ++ str;
  }
  return toRet;
}

static int isBigger(char *s1, char *s2) {
  return (int)(pf_len((const char *)s1) - pf_len((const char *)s2));
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

static int is_printable(char *str)
{
  char c;
  while((c = *str ++) != '\0')
    if ( ( c < ' ' ) || ( c > '~' ) )
      return 0;
  return 1;
}

static void pf_test42(int i)
{
  if ( i == 42 ) {
    if (write(1, "Y", 1)) {}
  } else {
    if (write(1, "N", 1)) {}
  }
  if (write(1, "\n", 1)) {}
}

static void ft_putnbr(int nb)
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

static int isEven(int n) {
    return ((n % 2) == 0);
}

static int minus(int a, int b) {
  return (a - b);
}

static void eol() {
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
  const char *strs[5];
  strs[0] = s1;
  strs[1] = s2;
  strs[2] = s3;
  strs[3] = s4;
  strs[4] = s5;
  pf_test42(40 + ft_count_if((char **)strs, 5, is_printable));
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
  char **strTab = (char **)malloc(33 * sizeof(char *));
  const char st1[5] = "Duke";
  const char st2[4] = "Joe";
  const char st3[8] = "Alberto";
  const char st4[7] = "Albert";
  const char st5[7] = "Yngmie";
  const char st6[4] = "Ali";
  const char st7[6] = "Bobby";
  const char st8[4] = "Bob";
  const char st9[8] = "Alberta";
  const char s10[4] = "Joe";
  const char s11[4] = "Zoe";
  const char s12[4] = "Gil";
  const char s13[5] = "Paul";
  const char s14[6] = "Aline";
  const char s15[5] = "Mike";
  const char s16[5] = "Jaco";
  const char s17[9] = "Graziela";
  const char s18[6] = "Jorge";
  const char s19[7] = "George";
  const char s20[7] = "Ernest";
  const char s21[6] = "Alice";
  const char s22[8] = "Tiffany";
  const char s23[7] = "Pamela";
  const char s24[6] = "Betty";
  const char s25[7] = "Joanna";
  const char s26[7] = "123456";
  const char s27[8] = "Michael";
  const char s28[4] = "Eve";
  const char s29[6] = "Janis";
  const char s30[5] = "Otis";
  const char s31[7] = "Barney";
  const char s32[8] = "George";
  strTab[0] = (char *)&st1;
  strTab[1] = (char *)&st2;
  strTab[2] = (char *)&st3;
  strTab[3] = (char *)&st4;
  strTab[4] = (char *)&st5;
  strTab[5] = (char *)&st6;
  strTab[6] = (char *)&st7;
  strTab[7] = (char *)&st8;
  strTab[8] = (char *)&st9;
  strTab[9] = (char *)&s10;
  strTab[10] = (char *)&s11;
  strTab[11] = (char *)&s12;
  strTab[12] = (char *)&s13;
  strTab[13] = (char *)&s14;
  strTab[14] = (char *)&s15;
  strTab[15] = (char *)&s16;
  strTab[16] = (char *)&s17;
  strTab[17] = (char *)&s18;
  strTab[18] = (char *)&s19;
  strTab[19] = (char *)&s20;
  strTab[20] = (char *)&s21;
  strTab[21] = (char *)&s22;
  strTab[22] = (char *)&s23;
  strTab[23] = (char *)&s24;
  strTab[24] = (char *)&s25;
  strTab[25] = (char *)&s26;
  strTab[26] = (char *)&s27;
  strTab[27] = (char *)&s28;
  strTab[28] = (char *)&s29;
  strTab[29] = (char *)&s30;
  strTab[30] = (char *)&s31;
  strTab[31] = (char *)&s32;
  strTab[32] = (char *)0;
  char *str = (char*)0;
  ft_sort_string_tab(strTab);
  it = argc - argc; //use argc and sets it to 0
  while ((str = strTab[it]) != (char *)0) {
    if (pf_print((const char *)str)) {}
    ++it;
  }
  it = 0;
  ft_advanced_sort_string_tab(strTab, &isBigger);
  while ((str = strTab[it]) != (char *)0) {
    if (pf_print((const char *)str)) {}
    ++ it;
  }
  it = 0;
  ft_advanced_sort_string_tab(strTab, ft_strcmp);
  while ((str = strTab[it]) != (char *)0) {
    if (pf_print((const char *)str)) {}
    ++ it;
  }
  if (strTab) {
    free(strTab);
    strTab = (char **)0;
  }
  return 0;
}
