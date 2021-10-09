char *ft_strlowcase(char *str)
{
  char *pc = str;
  char c;
  while( (c = *pc) != '\0')
    {
      if ( ( c >= 'A' ) && ( c <= 'Z' ) )
	*pc = c + 0x20;
      pc++;
    }
  return str;
}
