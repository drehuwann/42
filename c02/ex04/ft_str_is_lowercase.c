int ft_str_is_lowercase(char *str)
{
  char c;
  while((c = *str ++) != '\0')
    if ( ( c < 'a' ) || ( c > 'z' ) )
      return 0;
  return 1;
}
