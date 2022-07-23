void ft_foreach(int *tab, int length, void(*f)(int));
int *ft_map(int *tab, int length, int(*f)(int));
int ft_any(char **tab, int(*f)(char*));
int ft_count_if(char **tab, int length, int(*f)(char*));
int ft_is_sort(int *tab, int length, int(*f)(int, int));
void ft_sort_string_tab(char **tab);
int ft_strcmp(char *s1, char *s2);
void ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *));
