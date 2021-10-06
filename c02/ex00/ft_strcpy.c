char *ft_strcpy(char *dest, char *src)
{
  char *this = dest;
  while ( (*dest ++ = *src ++) != '\0');
  return this;
}
