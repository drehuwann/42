#include "./ft_list.h"

int ft_list_size(t_list *begin_list){
  int toRet = 0;
  t_list *el = begin_list;
  while(el) {
    el = el->next;
    ++ toRet;
  }
  return toRet;
}
