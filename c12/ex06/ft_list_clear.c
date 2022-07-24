#include "./ft_list.h"

#include <stdlib.h>

void ft_list_clear(t_list *begin_list, void (*free_fct)(void *)) {
  while (begin_list) {
    t_list *nextelem = begin_list->next;
    free_fct(begin_list->data);
    free((void *)begin_list);
    begin_list = nextelem;
  }
}
