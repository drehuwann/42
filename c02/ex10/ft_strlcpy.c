unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
  const char *osrc = src;
  unsigned int nleft = size;

  if (nleft != 0)
    while (--nleft != 0)
      {
	if ( (*dest++ = *src++) == '\0' )
	  break;
      }

  if (nleft == 0)
    {
      if (size != 0)
	*dest = '\0';
      while (*src++)
	;
    }

  return (src - osrc -1);
}
