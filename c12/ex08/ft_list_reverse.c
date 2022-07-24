#include "ft_list.h"

static int list_size(t_list *begin_list){
  int toRet = 0;
  t_list *el = begin_list;
  while(el) {
    el = el->next;
    ++ toRet;
  }
  return toRet;
}

static t_list *at(t_list *begin_list, unsigned int nbr) {
  t_list *toRet = begin_list;
  unsigned int it = 0;
  while (toRet && it < nbr) {
    toRet = toRet->next;
    ++ it;
  }
  return toRet;
}

/// @brief Puts the first elem in list at pos, shifting left pos-1 elements
static void rol(t_list **list, unsigned int pos) {
  t_list *tmpnext = at(*list, pos);
  t_list *elem = *list;
  *list = elem->next;
  elem->next = tmpnext->next;
  at(*list, pos -1)->next = elem;
}

void ft_list_reverse(t_list **begin_list){
  if (!begin_list) return;
  t_list *elem = *begin_list;
  int size = list_size(elem);
  int it = size -1;
  while (it > 0) {
    rol(begin_list, it);
    -- it;
  }
}
