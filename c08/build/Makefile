THIS_FILE := $(lastword $(MAKEFILE_LIST))
CC := gcc -Wall -Wextra -Werror $(DEBUG)

all:
	${CC} -Wno-unused-parameter ./tst01.c -I../ex01 -o ./tst01
	${CC} ./tst02.c -I../ex02 -o ./tst02
	${CC} ./tst03.c -I../ex03 -o ./tst03
	${CC} -c ../ex04/ft_strs_to_tab.c -I./ -o ft_strs_to_tab.o
	${CC} -c ../ex05/ft_show_tab.c -I./ -o ft_show_tab.o

	${CC} -c ./main.c -o ./main.o

	${CC} ./ft_strs_to_tab.o ./ft_show_tab.o main.o -o tst

debug:
	$(MAKE) $(THIS_FILE) DEBUG="-g -D_DEBUG" all
