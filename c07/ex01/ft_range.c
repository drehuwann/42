#include <stdlib.h>

int *ft_range(int min, int max)
{
  int size = max - min;
  if (size <= 0)
    return 0; // returns null pointer
  int *toReturn = (int*)(malloc(size));
  int *initialPtr = toReturn;
  while (min < max)
    {
      *toReturn ++ = min ++;
    }
  return initialPtr;
}
