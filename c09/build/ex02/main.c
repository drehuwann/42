#include <unistd.h>
#include <stdlib.h>
#include "./ft_split.h"

static int pf_strcmp(char *s1, char *s2)
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

static void pf_test42(int i)
{
  if ( i == 42 ) {
    if (write(1, "Y", 1)) {}
  } else {
    if (write(1, "N", 1)) {}
  }
  if (write(1, "\n", 1)) {}
}

int main (void)
{
  char **Array = ft_split("%%six#.fois%%%%sept.egalent#quarante-deux...",
			  ".#%");
  pf_test42(42 + pf_strcmp(Array[0], "six") + pf_strcmp(Array[1], "fois") +
	    pf_strcmp(Array[2], "sept") + pf_strcmp(Array[3], "egalent") +
	    pf_strcmp(Array[4], "quarante-deux") + (Array[5] != 0));
  for (int i = 0; i < 5; ++i)
    {
      if (Array[i])
	{
	  free(Array[i]);
	  Array[i] = 0;
	}

    }
  if (Array)
    {
      free(Array);
      Array = 0;
    }  

  Array = ft_split("six#.fois%%%%sept.egalent#quarante-deux...", ".#%");
  pf_test42(42 + pf_strcmp(Array[0], "six") + pf_strcmp(Array[1], "fois") +
	    pf_strcmp(Array[2], "sept") + pf_strcmp(Array[3], "egalent") +
	    pf_strcmp(Array[4], "quarante-deux") + (Array[5] != 0));
  for (int i = 0; i < 5; ++i)
    {
      if (Array[i])
	{
	  free(Array[i]);
	  Array[i] = 0;
	}

    }
  if (Array)
    {
      free(Array);
      Array = 0;
    }  
}
