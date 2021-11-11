#include <stdlib.h>

int pf_strlen(char *str)
{
  int result = 0;
  while ( *str++ )
    result ++;
  return result;
}

char *ft_strdup(char *src)
{
  char *toReturn = (char*)(malloc(pf_strlen(src)));
  char *initialStrPtr = toReturn;
  while (*src)
    {
      *toReturn ++ = *src ++;
    }
  return initialStrPtr;
}
