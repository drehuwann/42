#include "./ft_list.h"

t_list *ft_list_push_strs(int size, char **strs) {
  if (strs == (char **)0) return (t_list *)0;
  t_list *toRet = (t_list *)0;
  while (size) {
    --size;
    t_list *lastelem = toRet;
    toRet = ft_create_elem((void*)(*strs));
    toRet->next = lastelem;
    ++ strs; 
  }
  return toRet;
}
