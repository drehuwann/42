#include "./ft_list.h"

t_list *ft_list_at(t_list *begin_list, unsigned int nbr) {
  t_list *toRet = begin_list;
  unsigned int it = 0;
  while (toRet && it < nbr) {
    toRet = toRet->next;
    ++ it;
  }
  return toRet;
}
