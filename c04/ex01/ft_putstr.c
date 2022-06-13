#include <unistd.h>

void ft_putstr(char *str)
{
  while ( *str != 0)
    if (write (1, str ++, 1)) {}
}
