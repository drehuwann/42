#include "./ft_list.h"

#include <stdlib.h>

void ft_list_clear(t_list *begin_list, void (*free_fct)(void *)) {
  while (begin_list) {
    t_list *nextelem = begin_list->next;
    void *data_toFree = begin_list->data;
    if (data_toFree) {
      free_fct(data_toFree);
      data_toFree = (void *)0;
    }
    free((void *)begin_list);
    begin_list = nextelem;
  }
}
