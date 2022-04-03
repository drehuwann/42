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
      if (sep)
	{
	  int sepSize = pf_strLength(sep);
	  bigStrSize += (size - 1) * sepSize;
	}
      for (int i = 0; i < size; i++)
	bigStrSize += pf_strLength(*strs++);
      bigStrSize ++; // Adds room for null-termination
      toReturn = malloc(sizeof(*toReturn) * bigStrSize);
      char *pToChar = (char*)toReturn; 
      for (int i = 0 ; i < size; i++)
	{
	  char *strToJoin = firstStr[i];
	  char charToWrite = *strToJoin;
	  while (charToWrite)
	    {
	      *pToChar ++ = charToWrite;
	      charToWrite = *++strToJoin;
	    }
	  if ((sep) && (i < size - 1))
	    {
	      char *p_sep = sep;
	      while (*p_sep) *pToChar ++ = *p_sep ++;
	    }
	}
      *pToChar = 0; // null-terminate string
    }
  return toReturn;
}
