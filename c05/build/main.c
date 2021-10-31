#include <unistd.h>

#include "./protos.h"

void pf_test42(int i)
{
  if ( i == 42 )
    write(1, "Y", 1);
  else
    write(1, "N", 1);
  write(1, "\n", 1);
}

int main()
{
  pf_test42(42 + ft_iterative_factorial(-9));
  pf_test42(18 + ft_iterative_factorial(4));
  pf_test42(41 + ft_iterative_factorial(0));
  pf_test42(42 + ft_recursive_factorial(-9));
  pf_test42(18 + ft_recursive_factorial(4));
  pf_test42(41 + ft_recursive_factorial(0));
  pf_test42(10 + ft_iterative_power(2, 5));
  pf_test42(41 + ft_iterative_power(0, 0));
  pf_test42(42 + ft_iterative_power(42, -1));
  pf_test42(74 + ft_iterative_power(-2, 5));
  pf_test42(10 + ft_recursive_power(2, 5));
  pf_test42(41 + ft_recursive_power(0, 0));
  pf_test42(42 + ft_recursive_power(42, -1));
  pf_test42(74 + ft_recursive_power(-2, 5));
  pf_test42(2 * ft_fibonacci(8));
  pf_test42(42 + ft_fibonacci(0));
  pf_test42(41 + ft_fibonacci(1));
  pf_test42(ft_sqrt(42 * 42));
  pf_test42(42 + ft_sqrt(0));
  pf_test42(41 + ft_sqrt(1));
  pf_test42(42 + ft_sqrt(-16));
  pf_test42(12387 - ft_sqrt(12345*12345));
  pf_test42(42 + ft_is_prime(0));
  pf_test42(42 + ft_is_prime(1));
  pf_test42(41 + ft_is_prime(2));
  pf_test42(41 + ft_is_prime(3));
  pf_test42(42 + ft_is_prime(4));
  pf_test42(42 + ft_is_prime(1005));
  pf_test42(41 + ft_is_prime(3541));
  pf_test42(ft_find_next_prime(42) - 1);
  pf_test42(ft_find_next_prime(3734) - 3697); //3739
  //  write(1, "\n", 1);
}        
