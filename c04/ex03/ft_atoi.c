static int pf_isSign(char c) // returns -1 if '-'; +1 if '+'; 0 else
{
  if ( c == '-') return -1;
  if ( c == '+') return 1;
  return 0;
}

static int pf_isDigit(char c) // returns #c if c is digit, -1 else
{
  if (( c >= '0') && ( c <= '9'))
    return (c - '0');
  return -1;
}

int ft_atoi(char *str)
{
  int result = 0;
  int multiplier = 1; // to keep trace of the sign.
  int mult = 0;
  int digit= -1;
  
  while ( (*str == 0x20) || (*str == '\f') || (*str == '\n') || (*str == '\r')
	  || (*str == '\t') || (*str == '\v') )
    // flush leading spaces
    str ++;
  while ( (mult = pf_isSign(*str)) != 0 )
    {
      multiplier *= mult;
      str ++;
    }

  while ( (digit = pf_isDigit(*str)) != -1)
    {
      result *= 10;
      result += digit;
      str ++;
    } 

  return (multiplier * result);
}
