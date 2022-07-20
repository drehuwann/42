int ft_any(char **tab, int(*f)(char*)) {
  char *testedStr = (char *)0;
  while((testedStr = *tab)) {
    if (f(testedStr)) return 1;
    ++ tab;
  }
  return 0;
}
