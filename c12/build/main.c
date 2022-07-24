#include <stdlib.h>
#include <unistd.h>

#include "./protos.h"

static void print(const char *s) {
  if (s == NULL) print("can't dereference nullptr");
  char eol = '\n';
  while (*s) {
    if (write(1, s, 1)) {}
    ++ s;
  }
  if (write(1, &eol, 1)) {}
}

static void free_elem(t_list *el) {
  while (el != NULL) {
    t_list *next = el->next;
    free(el);
    el = next;
  }
}

int main() {
  char str[] = "Tea for two";
  char st2[] = "Two for tea";
  char st3[] = "For tea two";
  t_list *el = ft_create_elem((void *)str);
  if (el == NULL) {
    print("FAIL creating element");
  } else {
    if (el->next != NULL) print("'next' field not NULL");
    if (el->data == NULL) {
      print("'data' field is NULL");
    } else {
      if (*(char *)(el->data) != *str) {
	print("'data' field doesn't look right");
      } else {
	print((const char *)(el->data));
      }
    }
  }
  ft_list_push_front(&el, (void *)st2);
  print((const char *)(el->data));
  if (ft_list_size(el) != 2) print("FAIL : size is not 2");
  if (ft_list_size(NULL) != 0) print("FAIL : size(NULL) is not 0");
  ft_list_push_back(&el, (void *)st3);
  print((const char *)(ft_list_last(el)->data));
  free_elem(el);
  char **strs = (char **)malloc(3 * sizeof(char *));
  strs[0] = ft_strdup(st3);
  strs[1] = ft_strdup(st2);
  strs[2] = ft_strdup(str);
  el = ft_list_push_strs(3, strs);
  if (strs) {
    free(strs);
    strs = NULL;
  }
  t_list *el_remainder = el;
  while (el) {
    print((char *)(el->data));
    el = el->next;
  }
  el = el_remainder;
  unsigned int it = 0;
  while(it < (unsigned int)ft_list_size(el)) {
    print((const char *)((ft_list_at(el, it))->data));
    ++ it;
  }
  if (ft_list_at(el, it) || ft_list_at(el, 0xff)) {
    print("FAIL: ft_list_at out of bounds should return NULL");
  }
  it = 0;
  ft_list_clear(el, free);
}
