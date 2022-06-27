#include <stdlib.h>

static int pf_isspace(char c) // returns 0 -> false
{
  return ((c == 0x20) || (c == '\f') || (c == '\n') || (c == '\r') ||
	  (c == '\t') || (c == '\v'));
}

static int pf_is_Sign(char c) // returns -1 if '-'; +1 if '+'; 0 else
{
  if ( c == '-') return -1;
  if ( c == '+') return 1;
  return 0;
}

static int pf_is_InBase(char c, char *base)
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

static unsigned int pf_test_Base(char *base)
// returns 0 if base not valid, else returns baseSize
{
  char c = *base;
  unsigned int baseSize = 0;
  while ( c != 0 )
    {
      if (( pf_is_Sign(c) ) || ( pf_isspace(c) ))
	return 0;
      base ++;
      if (pf_is_InBase(c, base))
	return 0;
      baseSize ++;
      c = *base;
    }
  if (baseSize < 2)
    return 0;
  return baseSize;
}

static int pf_atoi_base(char *str, char *base, int *errCode)
{
  int result = 0;
  int multiplier = 1; // to keep trace of the sign.
  int mult = 0;
  int digit= -1;

  *errCode = 0;

  int baseSize = (int)pf_test_Base(base);
  // keeping pf_test_Base unsigned is buggy

  if (baseSize == 0)
    {
      *errCode = 1;
      return 0;
    }
  
  while ( pf_isspace(*str) )
    // flush leading spaces
    str ++;
  while ( (mult = pf_is_Sign(*str)) != 0 )
    {
      multiplier *= mult;
      str ++;
    }

  while ( (digit = pf_is_InBase(*str, base)) != 0)
    {
      result *= baseSize;
      result += digit - 1;
      str ++;
    } 

  return (multiplier * result);
}

static char *pf_itoa_base(int nb, char *base)
{
  int baseSize = (int)pf_test_Base(base);
  if (baseSize == 0) return NULL;
  int negative = ( nb < 0 ); //int for bool
  int nbDigits = 0;
  int tmpNb = nb;
  while (tmpNb)
    {
      tmpNb /= baseSize;
      ++ nbDigits;
    }
  if (negative)
      ++ nbDigits; // adds room for sign
  ++ nbDigits; //adds room for null-termination
  char *toReturn = (char*)malloc(nbDigits * sizeof(*toReturn));
  if (negative)
    {
      *toReturn = '-';
      tmpNb = -nb;
    } else { tmpNb = nb; }
  nbDigits --; 
  *(toReturn + nbDigits) = 0; //null-terminates
  nbDigits --;
  while(tmpNb)
    {
      *(toReturn + nbDigits) = base[tmpNb % baseSize];
      tmpNb /= baseSize;
      --nbDigits;
    }
  return toReturn;
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
  int errCode = 0;
  int value = pf_atoi_base(nbr, base_from, &errCode);
  if (errCode) return NULL;
  return pf_itoa_base(value, base_to);
}
