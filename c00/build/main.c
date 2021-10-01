#include "./ft_putchar.h"
#include "./ft_print_alphabet.h"
#include "./ft_print_reverse_alphabet.h"
#include "./ft_print_numbers.h"
#include "./ft_is_negative.h"
#include "./ft_print_comb.h"
#include "./ft_print_comb2.h"
#include "./ft_putnbr.h"
#include "./ft_print_combn.h"

int main()
{
  char *str="Hello you";
  while (*str != 0)
  {
    ft_putchar(*str);
    str++;
  }
  ft_putchar('\n');
  ft_print_alphabet();
  ft_putchar('\n');
  ft_print_reverse_alphabet();
  ft_putchar('\n');
  ft_print_numbers();
  ft_putchar('\n');
  ft_is_negative(-6);
  ft_putchar('\n');
  ft_is_negative(0);
  ft_putchar('\n');
  ft_is_negative(3);
  ft_putchar('\n');
  ft_print_comb();
  ft_putchar('\n');
  ft_print_comb2();
  ft_putchar('\n');
  ft_putnbr(0xffffffff);
  ft_putchar('\n');
  ft_putnbr(0x00000000);
  ft_putchar('\n');
  ft_putnbr(0x7fffffff);
  ft_putchar('\n');
  ft_putnbr(0x80000000);
  ft_putchar('\n');
  ft_putnbr(0x80000001);
  ft_putchar('\n');
  ft_putnbr(-123);
  ft_putchar('\n');
  ft_putnbr(17124);
  ft_putchar('\n');
  ft_putnbr(0xbadb055);
  ft_putchar('\n');
  ft_putnbr(0xcafebabe);
  ft_putchar('\n');
  ft_putnbr(0x5a5a55aa);
  ft_putchar('\n');
  ft_putnbr(0x00000001);
  ft_putchar('\n');
  for (int i = 1; i < 10; i++)
  {
    ft_print_combn(i);
    ft_putchar('\n');
  }
}
