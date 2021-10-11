int pf_isspace(char c) // returns 0 -> false
{
  return ((c == 0x20) || (c == '\f') || (c == '\n') || (c == '\r') ||
	  (c == '\t') || (c == '\v'));
}

int pf_is_Sign(char c) // returns -1 if '-'; +1 if '+'; 0 else
{
  if ( c == '-') return -1;
  if ( c == '+') return 1;
  return 0;
}

int pf_is_InBase(char c, char *base)
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

unsigned int pf_test_Base(char *base)
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

int ft_atoi_base(char *str, char *base)
{
  int result = 0;
  int multiplier = 1; // to keep trace of the sign.
  int mult = 0;
  int digit= -1;

  unsigned int baseSize = pf_test_Base(base);

  if (baseSize == 0)
    return 0;
  
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
