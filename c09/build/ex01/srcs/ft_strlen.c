#include "ft.h"

int ft_strlen(char *str)
{
  int result = 0;
  while ( *str++ )
    result ++;
  return result;
}
