#include <unistd.h>

#include "./protos.h"

#define INT_MIN -2147483648
#define INT_MAX 2147483647

void pf_test42(int i)
{
  if ( i == 42 ) {
    if (write(1, "Y", 1)) {}
  } else {
    if (write(1, "N", 1)) {}
  }
  if (write(1, "\n", 1)) {}
}

int main()
{
  pf_test42(ft_strlen("quarante-deux=trois*quatorze=quarante-deux"));
  ft_putstr("Normalement, ca doit ecrire sans accents ni cedilles. Et ca va a \
la ligne...\n");
  ft_putnbr(0xffffffff);
  if (write(1, "\n", 1)) {}
  ft_putnbr(0x00000000);
  if (write(1, "\n", 1)) {}
  ft_putnbr(0x7fffffff);
  if (write(1, "\n", 1)) {}
  ft_putnbr(0x80000000);
  if (write(1, "\n", 1)) {}
  ft_putnbr(0x80000001);
  if (write(1, "\n", 1)) {}
  ft_putnbr(-123);
  if (write(1, "\n", 1)) {}
  ft_putnbr(17124);
  if (write(1, "\n", 1)) {}
  ft_putnbr(0xbadb055);
  if (write(1, "\n", 1)) {}
  ft_putnbr(0xcafebabe);
  if (write(1, "\n", 1)) {}
  ft_putnbr(0x5a5a55aa);
  if (write(1, "\n", 1)) {}
  ft_putnbr(0x00000001);
  if (write(1, "\n", 1)) {}
  pf_test42(1276 + ft_atoi(" \f \r\n \v  \t  ---+--+1234ab567"));
  ft_putnbr_base(0, "!@#$");
  if (write(1, "\n", 1)) {}
  ft_putnbr_base(INT_MIN, "0123456789abcdef");
  if (write(1, "\n", 1)) {}
  ft_putnbr_base( -12, "!@#$");
  if (write(1, "\n", 1)) {}
  ft_putnbr_base(INT_MAX, "0123456789abcdef");
  if (write(1, "\n", 1)) {}
  ft_putnbr_base(-2147483647, "0123456789abcdef");
  if (write(1, "\n", 1)) {}
  ft_putnbr_base(-1, "0123456789abcdef");
  if (write(1, "\n", 1)) {}
  pf_test42(43 + ft_atoi_base("\t \nffffffffggggg", "0123456789abcdef")); 
  pf_test42(42 + ft_atoi_base("\t \nffffffffggggg", "012\n3456789abcdef"));
  pf_test42(42 + ft_atoi_base("\t \nffffffffggggg", "0123456789abcdeh"));
  pf_test42(ft_atoi_base("\t \n----+42", "0123456789")); 
}        
