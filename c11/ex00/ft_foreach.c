void ft_foreach(int *tab, int length, void(*f)(int)) {
  int it = 0;
  while (it < length) {
    f(tab[it]);
    ++it;
  }
}
