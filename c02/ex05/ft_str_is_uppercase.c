int ft_str_is_uppercase(char *str)
{
  char c;
  while((c = *str ++) != '\0')
    if ( ( c < 'A' ) || ( c > 'Z' ) )
      return 0;
  return 1;
}
