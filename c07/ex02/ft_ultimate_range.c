#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max)
{
  int size = max - min;
  if (size <= 0)
    {
      *range = 0; //NULL ptr
      return 0;
    }
  int *p_range = malloc(sizeof(*p_range) * size);
  if (p_range == 0) return -1; // malloc error
  int *beginRange = p_range;
  while (min < max)
    {
      *p_range ++ = min ++;
    }
  *range = beginRange;
  return size;
}
