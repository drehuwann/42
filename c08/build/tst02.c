#include "ft_abs.h"

#include <unistd.h>

void ft_putstr(char *str)
{
  while (*str)
  write(1, str++, 1);
}

int main()
{
  ft_putstr("Testing ABS(2) ... ");
  if (ABS(2) == 2)
    {
      ft_putstr("Ok\n");
    }
  else
    {
      ft_putstr("Failed\n");
    }
  ft_putstr("Testing ABS(-3.14) ... ");
  if (ABS(-3.14) == 3.14)
    {
      ft_putstr("Ok\n");
    }
  else
    {
      ft_putstr("Failed\n");
    }
  ft_putstr("Testing ABS(-0) ... ");
  if (ABS(-0) == 0)
    {
      ft_putstr("Ok\n");
    }
  else
    {
      ft_putstr("Failed\n");
    }
  return 0;
}
