int ft_iterative_factorial(int nb)
{
  if ( nb < 0 ) return 0;
  if ( nb == 0 ) return 1; // Mathematically correct
  int out = 1;
  for (int i = 1; i <= nb; i ++)
    out *= i;
  return out;
}
