#include "./ft_btree.h"

#include <stdlib.h>

typedef struct {
  t_btree *node;
  int level;
} levelledNode;

typedef struct s_nodeList{
  struct s_nodeList *next;
  levelledNode *node;
} t_nodeList;

static t_nodeList *createNode(t_btree *node, int level) {
  if (!node) return (t_nodeList *)0;
  levelledNode *levNode = (levelledNode *)malloc(sizeof(levelledNode));
  levNode->node = node;
  levNode->level = level;
  t_nodeList *toRet = (t_nodeList *)malloc(sizeof(t_nodeList));
  toRet->next = (t_nodeList *)0;
  toRet->node = levNode;
  return toRet;
}

static void pushbackNode(t_nodeList **list, t_btree *node, int level) {
  if (!node || !list) return;
  if (*list) {
    while ((*list)->next) {
      *list = (*list)->next;
    }
  }
  t_nodeList *newNode = createNode(node, level);
  if (*list) {
    (*list)->next = newNode;
  } else {
    *list = newNode;
  }
}

static levelledNode *popfrontNode(t_nodeList **list) {
  if (!list || !(*list)) return (levelledNode *)0;
  levelledNode *toRet = (*list)->node;
  t_nodeList *newList = (*list)->next;
  //if ((*list)->node) free((*list)->node);
  //free(*list);
  *list = newList;
  return toRet;
}

void btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
							int current_level,
							int is_first_elem)) {
  if (! root) return;
  int first = 1;
  t_nodeList *nodeList = createNode(root, 0);
  if (!nodeList) return;
  levelledNode *tempNode = popfrontNode(&nodeList);
  while(tempNode) {
    int lastLevel = tempNode->level;
    applyf(tempNode->node->item, tempNode->level, first);
    if (first) first = 0;
    if (tempNode->node->left) {
      pushbackNode(&nodeList, tempNode->node->left, tempNode->level + 1);
    }
    if (tempNode->node->right) {
      pushbackNode(&nodeList, tempNode->node->right, tempNode->level + 1);
    }
    tempNode = popfrontNode(&nodeList);
    if(tempNode && tempNode->level != lastLevel) first = 1;
  }
}
