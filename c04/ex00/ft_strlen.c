int ft_strlen(char *str)
{
  int out = 0;
  while (*str++)
    out++;
  return out;
}
