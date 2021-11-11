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
    free(returnedStringPtr);
  int *returnedIntPtr = ft_range(40, 43);
  pf_test42(2 + *returnedIntPtr ++);
  pf_test42(1 + *returnedIntPtr ++);
  pf_test42(*returnedIntPtr);  
}
