THIS_FILE := $(lastword $(MAKEFILE_LIST))
CC := gcc -Wall -Wextra -Werror $(DEBUG)
RM := rm -f

all:
	${CC} -c ../ex00/ft_foreach.c -I./ -o ft_foreach.o
	${CC} -c ../ex01/ft_map.c -I./ -o ft_map.o
	${CC} -c ../ex02/ft_any.c -I./ -o ft_any.o
	${CC} -c ../ex03/ft_count_if.c -I./ -o ft_count_if.o
	${CC} -c ../ex04/ft_is_sort.c -I./ -o ft_is_sort.o
	${CC} -c ../ex06/ft_sort_string_tab.c -I./ -o ft_sort_string_tab.o

	${CC} -c ./main.c -o ./main.o

	${CC} ./ft_foreach.o ./ft_map.o ./ft_any.o ./ft_count_if.o \
./ft_is_sort.o ./ft_sort_string_tab.o main.o -o tst

debug:
	$(MAKE) clean
	$(MAKE) $(THIS_FILE) DEBUG="-g -D_DEBUG" all

clean:
	$(RM) ./*.o ./tst

re:
	$(MAKE) clean
	$(MAKE) all
