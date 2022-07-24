#include "./ft_list.h"

void ft_list_push_back(t_list **begin_list, void *data) {
  t_list *elem = *begin_list;
  t_list *next = (t_list *)0;
  t_list *newelem = ft_create_elem(data);
  if (elem) {
    while ((next = elem->next)) {
      elem = next;
    }
    elem->next = newelem;
  } else {
    *begin_list = newelem;
  }
}
