#include <unistd.h>

#define INT_MIN -2147483648
#define INT_MAX 2147483647

int pf_isInBase(char c, char *base)
//returns pos(from one for first) for true; 0 for false
{
  int pos = 0;
  while ( *base != 0 )
    {
      pos ++;
      if ( *base == c )
	return pos;
      base ++;
    }
  return 0;
}

unsigned int pf_testBase(char *base)
// returns 0 if base not valid, else returns baseSize
{
  char c = *base;
  unsigned int baseSize = 0;
  while ( c != 0 )
    {
      if (( c == '+') || ( c== '-' ))
	return 0;
      base ++;
      if (pf_isInBase(c, base))
	return 0;
      baseSize ++;
      c = *base;
    }
  if (baseSize < 2)
    return 0;
  return baseSize;
}

int pf_strLength(char *str)
{
  int out = 0;
  while (*str ++ != 0)
    out ++;
  return out;
}

void pf_incr(char *str, char *base)
{
  char lastC = str[pf_strLength(str) - 1];
  if ( lastC == base[pf_testBase(base) - 1])
    {
      str[pf_strLength(str) - 1] = base[0];
      pf_incr(str, base);
    }
  else
    lastC = base[pf_isInBase(lastC, base)] + 1;
}

void ft_putnbr_base(int nb, char *base)
{
  if (nb == 0)
    {
      write(1, &base[0], 1);
      return;
    }
  unsigned int baseSize = pf_testBase(base);
  if ( ! baseSize )
    return;
  
  int negative = (nb < 0); // negative=0 -> positive; negative=1 -> negative
  int reste = 0;
  char reversedStr[64]; // max length of a int in base 2
  char *debutRevStr = &reversedStr[0];
  char *pRevStr = debutRevStr;
  int intMinHit = 0;

  if ( nb == INT_MIN )
    {
      intMinHit = 1;
    }
  if ( negative )
    nb *= -1;
  while ( nb != 0 )
    {
      reste = nb % baseSize;
      nb /= baseSize;
      char c = base[reste];
      if (( nb == 0 ) && ( intMinHit == 1))
	pf_incr(reversedStr, base);
      *pRevStr = c;
      pRevStr++;
    }
  *pRevStr = '\0'; //null-terminates str
  if (negative) write(1, "-", 1);
  while (pRevStr != debutRevStr)
    {
      pRevStr--;
      write(1, pRevStr, 1);
    }
}
