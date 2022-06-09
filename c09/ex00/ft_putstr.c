#include <unistd.h>

void ft_putstr(char *str)
{
  while (*str) {
    char c = *str;
    if (!write(1, &c, 1)) {
      ///TODO: Something when we have implemented exceptions
    }
    ++str;
  }
}
