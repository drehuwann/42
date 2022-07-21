int ft_count_if(char **tab, int length, int(*f)(char*)) {
  int toRet = 0;
  int it = 0;
  while (it < length) {
    toRet += f(tab[it]);
    ++ it;
  }
  return toRet;
}
