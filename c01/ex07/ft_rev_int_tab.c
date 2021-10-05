void ft_rev_int_tab(int *tab, int size)
{
  int *end = &tab[size -1];
  int tmp = 0;
  while ( end > tab )
    { //do swap
      tmp = *tab;
      *tab++ = *end;
      *end-- = tmp;
    }
}
