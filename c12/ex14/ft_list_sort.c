#include "./ft_list.h"

void ft_list_sort(t_list **begin_list, int (*cmp)()) {
  if (!begin_list) return;
  t_list *mixedHead = *begin_list;
  if (!mixedHead || !mixedHead->next) return;
  t_list *sortedHead = (t_list *)0;
  while (mixedHead) {
    t_list *currentElem = mixedHead;
    t_list **sortedAddr = &sortedHead;
    mixedHead = mixedHead->next;
    while (!(
        (!(*sortedAddr))
        || (cmp(currentElem->data, (*sortedAddr)->data) < 0))) {
      sortedAddr = &((*sortedAddr)->next);
    }
    currentElem->next = *sortedAddr;
    *sortedAddr = currentElem;
  }
  *begin_list = sortedHead;
}
