#include "./ft_list.h"

t_list *ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)()) {
  t_list *toRet = (t_list *)0;
  while(begin_list) {
    if (cmp(begin_list->data, data_ref)) {
      begin_list = begin_list->next;
    } else {
      toRet = begin_list;
      begin_list = (t_list *)0;
    }
  }
  return toRet;
}
