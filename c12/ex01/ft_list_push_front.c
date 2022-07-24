#include "./ft_list.h"

void ft_list_push_front(t_list **begin_list, void *data) {
  if (!begin_list) return;
  t_list *newelem = ft_create_elem(data);
  if (!newelem) return;
  newelem->next = *begin_list;
  *begin_list = newelem;
}
