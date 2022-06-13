#include "ft_stock_str.h"

#include <unistd.h>

void pf_putstr(char *str)
{
  char EOL = '\n';
  char *pEOL = &EOL;
  while (*str)
    if (write(1, str++, 1)) {}
  if (write(1, pEOL, 1)) {}
}

#define INT_MIN -2147483648
#define INT_MAX 2147483647

void pf_putnbr(int nb)
{
  if (nb == 0)
  {
    if (write(1, "0", 1)) {}
    return;
  }
  int negative = (nb < 0); // negative=0 -> positive; negative=1 -> negative
  char reste = 0;
  char reversedStr[11] = "8463847412"; //stores (string)nb from right to left
  // default value is INT_MIN
  char *debutRevStr = &reversedStr[0];
  char *pRevStr = debutRevStr;
  char EOL = '\n';
  char *pEOL = &EOL;

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
  if (write(1, pEOL, 1)) {}
}

void ft_show_tab(struct s_stock_str *par)
{
  while(par->str)
    {
      pf_putstr(par->str);
      pf_putnbr(par->size);
      pf_putstr(par->copy);
      ++par;
    }
}
