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

static int pf_strcmp(char *s1, char *s2)
{
  char result = *s1 - *s2;
  while (result == 0)
    {
      if ((*s1 == 0) || (*s2 == 0))
	return (int)(*s1 -*s2);
      result = *s1++ - *s2++;
    } 
  return (int)result;
}

static int strcmp_rule(void *a, void *b) {
  return pf_strcmp((char*)a, (char *)b);
}

/*! @brief swaps a and b if rule(*a, *b) returns negative number.
 * @return 1 if swap is done, else returns 0 */
static int pf_swap_if(void **a, void **b, int(*rule)(void*, void*)) {
  if (*a == *b || rule(*a, *b) <= 0)
    return 0;
  void *tmp = *a;
  *a = *b;
  *b = tmp;
  return 1;
}

static void pf_comb_sort(void **tab, int (*rule)(void*, void*)) {
  int size = pf_len_generic(tab);
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

void ft_sort_string_tab(char **tab) {
  pf_comb_sort((void **)tab, &strcmp_rule);
}
