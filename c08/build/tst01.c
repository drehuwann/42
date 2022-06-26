#include "ft_boolean.h"

void ft_putstr(char *str)
{
  while (*str)
  if (write(1, str++, 1)) {}
}

t_bool ft_is_even(int nbr)
{
  return ((EVEN(nbr)) ? TRUE : FALSE);
}

int main(int argc, char **argv)
{
  if (ft_is_even(argc - 1) == TRUE)
    ft_putstr(EVEN_MSG);
  else
    ft_putstr(ODD_MSG);
  return (SUCCESS);
}
