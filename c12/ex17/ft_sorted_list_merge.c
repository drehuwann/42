#include "./ft_list.h"

void ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)()) {
  if (! begin_list1 || ! begin_list2) return;
  t_list *p_list1 = *begin_list1;
  t_list *lastSorted = (t_list *)0;
  while (p_list1 && begin_list2) {
    if (cmp(p_list1->data, begin_list2->data) > 0) {
      if (lastSorted) {
        lastSorted->next = begin_list2;
      } else {
        *begin_list1 = begin_list2;
      }
      lastSorted = begin_list2;
      begin_list2 = begin_list2->next;
    } else {
      if (lastSorted) {
        lastSorted->next = p_list1;
      } else {
        *begin_list1 = p_list1;
      }
      lastSorted = p_list1;
      p_list1 = p_list1->next;
    }
  }
  if (!p_list1) {
    lastSorted->next = begin_list2;
  } else { // begin_list2 is NULL
    lastSorted->next = p_list1;
  }
}
