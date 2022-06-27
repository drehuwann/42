static unsigned int pf_strlen(char * s)
{
  unsigned int out = 0;
  while (*s++)
    out++;
  return out;
}

char * ft_strncat(char *dest, char *src, unsigned int nb)
{
  unsigned int dest_len = pf_strlen(dest);
  unsigned int i = 0;

  for (i = 0 ; i < nb && src[i] != '\0' ; i++)
    dest[dest_len + i] = src[i];
  dest[dest_len + i] = '\0';

  return dest;
}
