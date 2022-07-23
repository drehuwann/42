/*! @brief counts pointers from genArr to first nullptr.
 * @param genArr : address of an array
 * @return size of null terminateed array */
static int pf_len_generic(void **genArr) {
  int toRet = 0;
  while(genArr[toRet]) {
    ++ toRet;
  }
  return toRet;
}

/*! @brief swaps a and b if rule(*a, *b) returns negative number.
 * @return 1 if swap is done, else returns 0 */
static int pf_swap_if(char **a, char **b, int(*rule)(char*, char*)) {
  if (*a == *b || rule(*a, *b) <= 0)
    return 0;
  void *tmp = *a;
  *a = *b;
  *b = tmp;
  return 1;
}

static void pf_comb_sort(char **tab, int (*rule)(char*, char*)) {
  int size = pf_len_generic((void**)tab);
  int gap = size;
  float shrink = 1.3f;
  int swapped = 0;
  
  while (gap > 1 || swapped) {
    gap = (int)((float)gap / shrink);
    if (gap == 9 || gap == 10)
      gap = 11;
    if (gap < 1)
      gap = 1;
    swapped = 0;
    int index = 0;
    while (index < (size - gap)) {
      swapped += pf_swap_if(&(tab[index]), &(tab[index + gap]), rule);
      ++ index;
    }
  }
}

void ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *)) {
  pf_comb_sort(tab, cmp);
}
