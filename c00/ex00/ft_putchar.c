#include <unistd.h>

void ft_putchar(char c)
{
  if (write(1, &c, 1)) {}
}
