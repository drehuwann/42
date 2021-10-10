char *ft_strcat(char *dest, char *src)
{
  char* savDest = dest;
  while (*dest != 0)
    dest ++;
  while (*src != 0)
      *dest++ = *src++;
  return savDest;
}
