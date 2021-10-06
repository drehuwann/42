int ft_str_is_numeric(char *str)
{
  char c;
  while((c = *str ++) != '\0')
    if ( ( c < '0' ) || ( c > '9' ) )
      return 0;
  return 1;
}
