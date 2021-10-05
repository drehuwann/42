THIS_FILE := $(lastword $(MAKEFILE_LIST))
CC := gcc -Wall -Wextra -Werror $(DEBUG)

all:
	${CC} -c ../ex00/ft_ft.c -o ./ft_ft.o
	${CC} -c ../ex01/ft_ultimate_ft.c -o ./ft_ultimate_ft.o
	${CC} -c ../ex02/ft_swap.c -o ./ft_swap.o
	${CC} -c ../ex03/ft_div_mod.c -o ./ft_div_mod.o
	${CC} -c ../ex04/ft_ultimate_div_mod.c -o ./ft_ultimate_div_mod.o
	${CC} -c ../ex05/ft_putstr.c -o ./ft_putstr.o
	${CC} -c ../ex06/ft_strlen.c -o ./ft_strlen.o
	${CC} -c ../ex07/ft_rev_int_tab.c -o ./ft_rev_int_tab.o
	${CC} -c ../ex08/ft_sort_int_tab.c -o ./ft_sort_int_tab.o
	${CC} -c ./main.c -o ./main.o
	${CC} ./ft_ft.o ./ft_ultimate_ft.o ./ft_swap.o ./ft_div_mod.o ./ft_ultimate_div_mod.o ./ft_putstr.o ./ft_strlen.o ./ft_rev_int_tab.o ./ft_sort_int_tab.o ./main.o -o tst

debug:
	$(MAKE) $(THIS_FILE) DEBUG="-g -D_DEBUG" all
