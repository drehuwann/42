#include <stdlib.h>

int pf_strLength(char *str)
{
  int out = 0;
  while (*str++)
    out++;
  return out;
}

char *ft_strjoin(int size, char **strs, char *sep)
{
  char *toReturn;
  char **firstStr = strs; // save 1st element adress.
  int bigStrSize = 0;
  if (size == 0)
    {
      toReturn = malloc(sizeof(*toReturn));
      *toReturn = 0;
    }
  else
    {
      for (int i = 0; i < size; i++)
	bigStrSize += pf_strLength(*strs++);
      if (sep) bigStrSize += size - 1;
      bigStrSize ++; // Adds room for null-termination
      toReturn = malloc(sizeof(*toReturn) * bigStrSize);
      char *pToChar = (char*)toReturn; 
      for (int i = 0 ; i < size; i++)
	{
	  char charToWrite = *firstStr[i];
	  while (charToWrite)
	    {
	      *pToChar ++ = charToWrite;
	      charToWrite = *++firstStr[i];
	    }
	  if ((sep) && (i < size - 1))
	    while (*sep) *pToChar ++ = *sep ++;
	}
      *pToChar = 0; // null-terminate string
    }
  return toReturn;
}
