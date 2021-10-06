int ft_str_is_alpha(char *str)
{
  char c;
  while((c = *str ++) != '\0')
    if ( (c < 'A') || ( (c > 'Z') && (c < 'a') ) || (c > 'z') )
      return 0;
  return 1;
}
