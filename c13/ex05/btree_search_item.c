#include "./ft_btree.h"

static void *infix(t_btree *root, void *data_ref, int (*cmpf)(void *, void *)) {
  void *toRet = (void *)0;
  if (!root) return toRet;
  if(root->left) {
    toRet = infix(root->left, data_ref, cmpf);
  }
  if (cmpf(root->item, data_ref) == 0) {
    toRet = root->item;
  }
  if(root->right) {
    toRet = infix(root->right, data_ref, cmpf);
  }
  return toRet;
}

void *btree_search_item(t_btree *root, void *data_ref,
			int (*cmpf)(void *, void *)) {
  return infix(root, data_ref, cmpf);
}
