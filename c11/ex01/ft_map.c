#include <stdlib.h>

int *ft_map(int *tab, int length, int(*f)(int)) {
  int it = 0;
  int *toRet = (int *)malloc(length * sizeof(*toRet));
  while (it < length) {
    toRet[it] = f(tab[it]);
    ++ it;
  }
  return toRet;
}
