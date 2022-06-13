#include "./protos.h"
#include "./ft_stock_str.h"

#include <unistd.h>
#include <stdlib.h>

int pf_strcmp(char *s1, char *s2)
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

void pf_test42(int i)
{
  if ( i == 42 ) {
    if (write(1, "Y", 1)) {}
  } else {
    if (write(1, "N", 1)) {}
  }
  if (write(1, "\n", 1)) {}
}

int main (void)
{
  int cmd = system("./tst01 && ./tst01 arg1 arg2 arg3");
  pf_test42(42 + cmd);
  cmd = system("./tst02");
  pf_test42(42 + cmd);
  cmd = system("./tst03");
  pf_test42(42 + cmd);
  char *strTab[4] = {"trois","fois","quatorze","42"};
  t_stock_str *rtrnTab = ft_strs_to_tab(4, strTab);
  for (int i = 0; i < 4; ++i)
    {
      if (i != 3)
	pf_test42(42 + (rtrnTab[i].str != strTab[i]));
      else pf_test42(42 + (rtrnTab[i].str != NULL));
      pf_test42(42 + pf_strcmp(rtrnTab[i].copy, strTab[i]));
    }
  ft_show_tab(rtrnTab);
  for (int i = 0; i < 4; ++i)
    {
      free(rtrnTab[i].copy);
      rtrnTab[i].copy = NULL;
    }
  free(rtrnTab);
  rtrnTab = NULL;
  return 0;
}
