int ft_strcmp(char *s1, char *s2)
{
  char result = *s1 - *s2;
  while (result == 0)
    {
      if ((*s1 == 0) || (*s2 == 0))
	return (int)(*s1 -*s2);
      result = *s1++ - *s2++;
    } 
  return (int)result;
}
