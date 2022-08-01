#include "./protos.h"

#include <stdlib.h>
#include <unistd.h>

static void print(const char *s) {
  if (s == NULL) {
    print("can't dereference nullptr");
    return;
  }
  char eol = '\n';
  while (*s) {
    if (write(1, s, 1)) {}
    ++ s;
  }
  if (write(1, &eol, 1)) {}
}

static void freeTree(t_btree *tree) {
  btree_apply_suffix(tree, free);
}

static void myPrint(void *item) {
  print((const char *)item);
}

static int cmpfn(void *a, void *b) {
  return ft_strcmp((char *)a, (char *)b);
}

int main() {
  t_btree *el = btree_create_node(ft_strdup("Root"));
  if (!el) {
    print("Failed to allocate binary tree node");
  } else {
    print("Succesfully allocated binary node with node->item :");
    print((const char *)el->item);
    if (el->left) {
      print("node->left should be NULL, but is not");
    }
    if (el->right) {
      print("node->right should be NULL, but is not");
    }
  }
  el->left = btree_create_node(ft_strdup("Root->Left"));
  el->right = btree_create_node(ft_strdup("Root->Right"));
  el->left->right = btree_create_node(ft_strdup("Root->Left->Right"));
  el->right->left = btree_create_node(ft_strdup("Root->Right->Left"));
  el->right->right = btree_create_node(ft_strdup("Root->Right->Right"));
  el->right->left->right = btree_create_node(ft_strdup(
    "Root->Right->Left->Right"));
  print("Prefix reading");
  btree_apply_prefix(el, myPrint);
  print("Infix reading");
  btree_apply_infix(el, myPrint);
  print("Suffix reading");
  btree_apply_suffix(el, myPrint);
  t_btree *new_tree = (t_btree *)0;
  btree_insert_data(&new_tree, (void *)ft_strdup("Jack"), &cmpfn);
  btree_insert_data(&new_tree, (void *)ft_strdup("Joe"), &cmpfn);
  btree_insert_data(&new_tree, (void *)ft_strdup("Averell"), &cmpfn);
  btree_insert_data(&new_tree, (void *)ft_strdup("William"), &cmpfn);
  btree_insert_data(&new_tree, (void *)ft_strdup("Ma"), &cmpfn);
  btree_insert_data(&new_tree, (void *)ft_strdup("Lucky"), &cmpfn);
  btree_insert_data(&new_tree, (void *)ft_strdup("Luke"), &cmpfn);
  print("Infix reading");
  btree_apply_infix(new_tree, myPrint);
  print("searching 'Luke' :");
  myPrint(btree_search_item(new_tree, (void *)("Luke"), cmpfn));
  print("searching 'Vador' :");
  myPrint(btree_search_item(new_tree, (void *)("Vador"), cmpfn));
  print("depth of el :");
  ft_putnbr(btree_level_count(el));
  print("\ndepth of new_tree :");
  ft_putnbr(btree_level_count(new_tree));
  print("\ndepth of (b_tree *)0 :");
  ft_putnbr(btree_level_count((t_btree *)0));
  print("\n");
  freeTree(new_tree);
  freeTree(el);
  return 0;
}
