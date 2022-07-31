#include "./ft_btree.h"

#include <stdlib.h>

t_btree *btree_create_node(void *item) {
  t_btree *toRet = (t_btree *)malloc(sizeof(t_btree));
  if (!toRet) return toRet;
  toRet->item = item;
  toRet->left = (t_btree *)0;
  toRet->right = (t_btree *)0;
  return toRet;
}
