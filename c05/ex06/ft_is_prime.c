int ft_is_prime(int nb)
{
  //returns 1 = true; 0 = false
  //algo from rosetta.org
  if ( !(nb & 1) || (nb < 2) )
    return (nb == 2);

  //comparing p*p <= nb can overflow
  for (int p = 3; p <= nb / p; p += 2)
    if ( !(nb % p) )
      return 0;
  return 1;
}
