THIS_FILE := $(lastword $(MAKEFILE_LIST))
CC := gcc -Wall -Wextra -Werror $(DEBUG)

all:
	${CC} -c ../ex00/ft_strcmp.c -o ./ft_strcmp.o
	${CC} -c ../ex01/ft_strncmp.c -o ./ft_strncmp.o
	${CC} -c ../ex02/ft_strcat.c -o ./ft_strcat.o
	${CC} -c ../ex03/ft_strncat.c -o ./ft_strncat.o
	${CC} -c ../ex04/ft_strstr.c -o ./ft_strstr.o
	${CC} -c ../ex05/ft_strlcat.c -o ./ft_strlcat.o

	${CC} -c ./main.c -o ./main.o

	${CC} ./ft_strcmp.o ./ft_strncmp.o ./ft_strcat.o ./ft_strncat.o ./ft_strstr.o ./ft_strlcat.o ./main.o -o tst

debug:
	$(MAKE) $(THIS_FILE) DEBUG="-g -D_DEBUG" all
