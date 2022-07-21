int ft_is_sort(int *tab, int length, int(*f)(int, int)) {
  typedef enum {
    decr = -1,
    eq = 0,
    cresc = 1
  } progression;
  progression lastProg = eq;
  progression prog = lastProg;
  int f_ret = 0;
  int it = 1;
  while (it < length) {
    f_ret = f(tab[it -1], tab[it]);
    if (f_ret < 0) {
      prog = cresc;
    } else if (f_ret == 0) {
      prog = eq;
    } else {
      prog = decr;
    }
    if (lastProg == eq) {
      lastProg = prog;
    } else {
      if (prog == eq)
	prog = lastProg;
      if (prog != lastProg)
	return 0;
    }
    ++ it;
  }
  return 1;
}
