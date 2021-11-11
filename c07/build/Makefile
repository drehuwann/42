THIS_FILE := $(lastword $(MAKEFILE_LIST))
CC := gcc -Wall -Wextra -Werror $(DEBUG)

all:
	${CC} -c ../ex00/ft_strdup.c -o ./ft_strdup.o
	${CC} -c ../ex01/ft_range.c -o ./ft_range.o

	${CC} -c ./main.c -o ./main.o

	${CC} ./ft_strdup.o ./ft_range.o ./main.o -o tst

debug:
	$(MAKE) $(THIS_FILE) DEBUG="-g -D_DEBUG" all
