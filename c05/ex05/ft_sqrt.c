int ft_sqrt(int nb)
{
  // algo found on rosettacode.org/wiki/Isqrt_(integer_square_root)_of_X#C
  int q = 1;
  int r = 0;
  int x = nb;

  while (q <= nb)
    q <<= 2; // 1, 4, 16 .. until q > nb

  while (q > 1)
    {
      q >>= 2;
      int t = x - r - q;
      r >>= 1;  // r *= 2
      if ( t >= 0 )
	{
	  x = t;
	  r += q;
	}
    }
  if ((r * r) != nb)
    r = 0;
  return r;
}
