#include "./ft_list.h"

static int listLen(t_list *list) {
  if (!list) return -1;
  int toRet = 0;
  while(list) {
    ++ toRet;
    list = list->next;
  }
  return toRet;
}

static t_list *at(t_list *list, unsigned int pos) {
  unsigned int it = 0;
  while(it < pos) {
    ++it;
    list = list->next;
  }
  return list;
}

static void swapData(t_list *a, t_list *b) {
  if (!a || !b) return;
  void *tmp = a->data;
  a->data = b->data;
  b->data = tmp;
}

void ft_list_reverse_fun(t_list *begin_list) {
  if (!begin_list || !(begin_list->next)) return;
  int size = listLen(begin_list);
  int it = 0;
  while(it < size / 2) {
    swapData(at(begin_list, it), at(begin_list, size - 1 - it));
    ++it;
  }
}
