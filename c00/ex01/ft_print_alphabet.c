#include <unistd.h>

void ft_print_alphabet(void)
{
  for (char c = 'a'; c <= 'z'; c++)
  {
    if (write(1, &c, 1)) {}
  }
}
