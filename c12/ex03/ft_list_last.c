#include "./ft_list.h"

t_list *ft_list_last(t_list *begin_list) {
  t_list *elem = begin_list;
  t_list *next = (t_list*)0;
  while ((next = elem->next)) {
    elem = next;
  }
  return elem;
}
