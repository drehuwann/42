int ft_str_is_printable(char *str)
{
  char c;
  while((c = *str ++) != '\0')
    if ( ( c < ' ' ) || ( c > '~' ) )
      return 0;
  return 1;
}
