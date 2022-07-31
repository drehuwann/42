#include "./ft_btree.h"

char *ft_strdup(char *src);
int ft_strcmp(char *s1, char *s2);

t_btree *btree_create_node(void *item);
void btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void btree_apply_infix(t_btree *root, void (*applyf)(void *));
void btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void btree_insert_data(t_btree **root, void *item,
		       int (*cmpf)(void *, void *));
