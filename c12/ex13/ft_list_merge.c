#include "./ft_list.h"

void ft_list_merge(t_list **begin_list1, t_list *begin_list2) {
  if (!begin_list1) return;
  t_list *el = *begin_list1;
  while (el) {
    if (el->next) {
      el = el->next;
    } else {
      el->next = begin_list2;
      break;
    }
  }
}
