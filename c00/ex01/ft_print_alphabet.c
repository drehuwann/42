#include <unistd.h>

void ft_print_alphabet(void)
{
  for (char c = 'a'; c <= 'z'; c++)
  {
    write(1, &c, 1);
  }
}
