#include "ft_stock_str.h"

#include <stdlib.h>

static int pf_len(const char *str)
{
  int result = 0;
  while ( *str++ )
    result ++;
  return result;
}

static char *pf_strdup(char *src)
{
  char *toReturn = (char*)(malloc(pf_len(src) + 1));
  char *initialStrPtr = toReturn;
  while (*src)
    {
      *toReturn ++ = *src ++;
    }
  *toReturn = 0; //null-terminate string
  return initialStrPtr;
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
  t_stock_str *toRet = NULL;
  if (ac <= 0) return toRet;
  toRet = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
  if (toRet == NULL) return toRet;
  // now toRet is valid so immediately null-terminates it :
  toRet[ac].str = NULL;
  // next is optionnal, but is best, for coherence :
  toRet[ac].size = 0;
  toRet[ac].copy = NULL;
  // now we can safely decrement ac to iterate : 
  t_stock_str *p_toRet = toRet;
  while (ac > 0)
    {
      char *st = *av;
      p_toRet->size = pf_len(st);
      p_toRet->str = st;
      p_toRet->copy = pf_strdup(st);
      -- ac;
      if (ac == 0)
	break;
      ++ av;
      ++ p_toRet;
    }
  return toRet;
}
