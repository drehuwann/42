char *ft_strupcase(char *str)
{
  char *pc = str;
  char c;
  while( (c = *pc) != '\0')
    {
      if ( ( c >= 'a' ) && ( c <= 'z' ) )
	*pc = c - 0x20;
      pc++;
    }
  return str;
}
