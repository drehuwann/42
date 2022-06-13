#include <unistd.h>

void ft_is_negative(int n)
{
  char *rep = "N";
  if (n < 0) rep = "N";
  else rep = "P";
  if (write (1, rep, 1)) {} 
}
