#include "./ft_list.h"

void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)()) {
  if (!begin_list || !cmp) return;
  t_list *elem = *begin_list;
  t_list *last_elem = (t_list *)0;
  t_list *newelem = ft_create_elem(data);
  int inserted = 0;
  while (elem) {
    if (cmp(data, elem->data) >= 0) {
      last_elem = elem;
      elem = elem->next;
    } else {
      newelem->next = elem;
      if (elem == *begin_list) {
        *begin_list = newelem;
      } else {
        last_elem->next = newelem;
      }
      inserted = 1;
      break;
    }
  }
  if (!inserted) {
    newelem->next = (t_list *)0;
    last_elem->next = newelem;
  }
}
