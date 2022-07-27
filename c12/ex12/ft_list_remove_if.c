#include "./ft_list.h"

#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		       void (*free_fct)(void *)) {
  if (!begin_list) return;
  t_list *elem = *begin_list;
  t_list *prev = (t_list *)0;
  while (elem) {
    t_list *next = elem->next;
    if(cmp(elem->data, data_ref) == 0) {
      if (prev) {
	prev->next = next;
      } else {
	*begin_list = next;
      }
      next = elem->next;
      free_fct(elem);
    } else {
      prev = elem;
    }
    elem = next;
  }
}
