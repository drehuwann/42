THIS_FILE := $(lastword $(MAKEFILE_LIST))
CC := gcc -Wall -Wextra -Werror $(DEBUG)

all:
	${CC} -c ../ex00/ft_strdup.c -o ./ft_strdup.o
	${CC} -c ../ex01/ft_range.c -o ./ft_range.o
	${CC} -c ../ex02/ft_ultimate_range.c -o ./ft_ultimate_range.o
	${CC} -c ../ex03/ft_strjoin.c -o ./ft_strjoin.o
	${CC} -c ../ex04/ft_convert_base.c -o ./ft_convert_base.o

	${CC} -c ./main.c -o ./main.o

	${CC} ./ft_strdup.o ./ft_range.o ./ft_ultimate_range.o ./ft_strjoin.o \
ft_convert_base.o main.o -o tst

debug:
	$(MAKE) $(THIS_FILE) DEBUG="-g -D_DEBUG" all
