
#include <unistd.h>

void ft_print_reverse_alphabet(void)
{
  for (char c = 'z'; c >= 'a'; c--)
  {
    if (write(1, &c, 1)) {}
  }
}
