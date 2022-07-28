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

static void genfn(void *data) {
  if (ft_strupcase((char *)data)) {}
}

static void genfn2(void *data) {
  if (ft_strlowcase((char *)data)) {}
}

void printList(t_list *el) {
  unsigned int it = 0;
  while(it < (unsigned int)ft_list_size(el)) {
    print((const char *)((ft_list_at(el, it))->data));
    ++ it;
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
  t_list *first = el;
  if (strs) {
    free(strs);
    strs = NULL;
  }
  while (el) {
    print((char *)(el->data));
    el = el->next;
  }
  el = first;
  printList(el);
  if (ft_list_at(el, ft_list_size(el)) || ft_list_at(el, 0xff)) {
    print("FAIL: ft_list_at out of bounds should return NULL");
  }
  el = first;
  ft_list_reverse(&el);
  printList(el);
  ft_list_foreach(el, genfn);
  printList(el);
  ft_list_foreach_if(el, genfn2, "FOR TEA TWO", ft_strcmp);
  printList(el);
  print("ft_list_find returns :");
  t_list *firstHit = ft_list_find(el, "TWO FOR TEA", ft_strcmp);
  if (firstHit) {
    print ((const char *)(firstHit->data));
  } else {
    print("Not found");
  }
  ft_list_push_front(&el, (void *)(ft_strdup("TWO FOR TEA")));
  ft_list_push_back(&el, (void *)(ft_strdup("TWO FOR TEA")));
  ft_list_push_front(&el, (void *)(ft_strdup("TWO FOR TEA")));
  print("list is now:");
  printList(el);
  ft_list_remove_if(&el, "TWO FOR TEA", ft_strcmp, free); 
  print("after remove_if, list is :");
  printList(el);
  strs = (char **)malloc(3 * sizeof(char *));
  strs[0] = ft_strdup(st3);
  strs[1] = ft_strdup(st2);
  strs[2] = ft_strdup(str);
  ft_list_merge(&el, ft_list_push_strs(3, strs));
  if (strs) {
    free(strs);
    strs = NULL;
  }
  print("after merge, list is :");
  printList(el);
  ft_list_sort(&el, ft_strcmp);
  print("after sort, list is :");
  printList(el);
  print("sorting already triaged list gives :");
  ft_list_sort(&el, ft_strcmp);
  printList(el);
  print("reversing list gives :");
  ft_list_reverse(&el);
  printList(el);
  print("sorting reversed list :");
  ft_list_sort(&el, ft_strcmp);
  printList(el);
  print("last reversed by value gives :");
  ft_list_reverse_fun(el);
  printList(el);
  print("after pushing back 'FOR TEA TWO', reversed by value gives :");
  ft_list_push_back(&el, (void*)ft_strdup("FOR TEA TWO"));
  ft_list_reverse_fun(el);
  printList(el);
  ft_list_clear(el, free);
}
