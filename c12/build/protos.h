#include "./ft_list.h"

char *ft_strdup(char *src);
char *ft_strupcase(char *src);

t_list *ft_create_elem(void *data);
void ft_list_push_front(t_list **begin_list, void *data);
int ft_list_size(t_list *begin_list);
t_list *ft_list_last(t_list *begin_list);
void ft_list_push_back(t_list **begin_list, void *data);
t_list *ft_list_push_strs(int size, char **strs);
void ft_list_clear(t_list *begin_list, void (*free_fct)(void *));
t_list *ft_list_at(t_list *begin_list, unsigned int nbr);
void ft_list_reverse(t_list **begin_list);
void ft_list_foreach(t_list *begin_list, void (*f)(void *));