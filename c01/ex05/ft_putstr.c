#include <unistd.h>

void ft_putstr(char *str)
{
  while (*str)
    if (write(1, str++, 1)) {}
}
