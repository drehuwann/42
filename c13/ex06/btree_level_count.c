#include "./ft_btree.h"

static int max(int a, int b) {
  if (b > a) return b;
  return a;
}

int btree_level_count(t_btree *root) {
  int toRet = 0;
  if (root == (t_btree *)0) return toRet;
  toRet = 1;
  toRet += max(btree_level_count(root->left), btree_level_count(root->right));
  return toRet;
}
