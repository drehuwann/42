void ft_rev_int_tab(int *tab, int size)
{
  int *end = &tab[size -1];
  while ( end > tab )
    { //do swap
      int tmp = *tab;
      *tab++ = *end;
      *end-- = tmp;
    }
}
