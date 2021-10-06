THIS_FILE := $(lastword $(MAKEFILE_LIST))
CC := gcc -Wall -Wextra -Werror $(DEBUG)

all:
	${CC} -c ../ex00/ft_strcpy.c -o ./ft_strcpy.o
	${CC} -c ../ex01/ft_strncpy.c -o ./ft_strncpy.o
	${CC} -c ../ex02/ft_str_is_alpha.c -o ./ft_str_is_alpha.o
	${CC} -c ../ex03/ft_str_is_numeric.c -o ./ft_str_is_numeric.o
	${CC} -c ../ex04/ft_str_is_lowercase.c -o ./ft_str_is_lowercase.o
	${CC} -c ../ex05/ft_str_is_uppercase.c -o ./ft_str_is_uppercase.o
	${CC} -c ../ex06/ft_str_is_printable.c -o ./ft_str_is_printable.o
	${CC} -c ./main.c -o ./main.o
	${CC} ./ft_strcpy.o ./ft_strncpy.o ./ft_str_is_alpha.o ./ft_str_is_numeric.o ./ft_str_is_lowercase.o ./ft_str_is_uppercase.o ./ft_str_is_printable.o ./main.o -o tst

debug:
	$(MAKE) $(THIS_FILE) DEBUG="-g -D_DEBUG" all
