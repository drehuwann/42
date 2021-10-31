int ft_iterative_power(int nb, int power)
{
  if ( power < 0 ) return 0;
  if ( power == 0 ) return 1; // Mathematically correct
  int out = 1;
  for (int i = 0; i < power; i ++)
    out *= nb;
  return out;
}
