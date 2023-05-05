static unsigned int pf_len(char *s)
{
  unsigned int out = 0;
  while (*s++)
    out++;
  return out;
}

char *ft_strstr(char *str, char *to_find)
{
  if (( to_find == 0 ) || (str == 0 )) return 0;
  int hit = 1;
  unsigned int toFindSize = pf_len(to_find);
  unsigned int strSize = pf_len(str);
  for (char *out = str; out < str + strSize - toFindSize ; out ++)
    {
      for (unsigned int i = 0; (i < toFindSize) && (hit == 1); i++)
	{
	  if ( out[i] != to_find[i] )
	    hit = 0;
	}
      if (hit == 1)
	return out;
      else hit = 1;
    }
  return 0;
}
