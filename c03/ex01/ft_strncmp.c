int ft_strncmp(char *s1, char *s2, unsigned int n)
{
  if (n == 0) return 0;
  char result = *s1 - *s2;
  while ( (result == 0) && (n-- > 0) )
    {
      if ((*s1 == 0) || (*s2 == 0))
	return (int)(*s1 -*s2);
      result = *s1++ - *s2++;
    } 
  return (int)result;
}
