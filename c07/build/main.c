#include <unistd.h>
#include <stdlib.h>
#include "./protos.h"

int pf_strcmp(char *s1, char *s2)
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

void pf_test42(int i)
{
  if ( i == 42 )
    write(1, "Y", 1);
  else
    write(1, "N", 1);
  write(1, "\n", 1);
}

int main (void)
{
  char *returnedStringPtr = ft_strdup("Quarante-Deux");
  pf_test42 ( 42 + pf_strcmp(returnedStringPtr, "Quarante-Deux") );
  if (returnedStringPtr)
    {
      free(returnedStringPtr);
      returnedStringPtr = 0;
    }
  int *returnedIntPtr = ft_range(40, 43);
  int *toFree = returnedIntPtr;
  pf_test42(2 + *returnedIntPtr ++);
  pf_test42(1 + *returnedIntPtr ++);
  pf_test42(*returnedIntPtr);
  if (toFree)
    {
      free(toFree);
      toFree= 0;
    }
  int *range = 0;
  int **ultimateRange = &range;
  pf_test42(41 + ft_ultimate_range(ultimateRange, 42, 42) + !(*ultimateRange));
  pf_test42(39 + ft_ultimate_range(ultimateRange, 40, 43));
  int *p_range = *ultimateRange;
  toFree = p_range;
  pf_test42(2 + *p_range ++);
  pf_test42(1 + *p_range ++);
  pf_test42(*p_range);
  if (toFree)
    {
      free(toFree);
      toFree = 0;
    }
  char *strArray[4];
  strArray[0] = ft_strdup("six");
  strArray[1] = ft_strdup("fois");
  strArray[2] = ft_strdup("sept");
  strArray[3] = ft_strdup("42");
  char* sepa = " ";
  returnedStringPtr = ft_strjoin(0, strArray, sepa);
  pf_test42(41 + ((char)*returnedStringPtr == 0));
  if (returnedStringPtr)
    {
      free(returnedStringPtr);
      returnedStringPtr = 0;
    }
  returnedStringPtr = ft_strjoin(4, strArray, sepa);
  pf_test42(42 + pf_strcmp(returnedStringPtr, "six fois sept 42"));
  if (returnedStringPtr)
    {
      free(returnedStringPtr);
      returnedStringPtr = 0;
    }
  returnedStringPtr = ft_strjoin(4, strArray, "3*7=42");
  pf_test42(42 + pf_strcmp(returnedStringPtr,
			   "six3*7=42fois3*7=42sept3*7=4242"));
  if (returnedStringPtr)
    {
      free(returnedStringPtr);
      returnedStringPtr = 0;
    }
}
