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
	${CC} -c ../ex07/ft_strupcase.c -o ./ft_strupcase.o
	${CC} -c ../ex08/ft_strlowcase.c -o ./ft_strlowcase.o
	${CC} -c ../ex09/ft_strcapitalize.c -o ./ft_strcapitalize.o
	${CC} -c ../ex10/ft_strlcpy.c -o ./ft_strlcpy.o
	${CC} -c ../ex11/ft_putstr_non_printable.c -o ./ft_putstr_non_printable.o
	${CC} -c ../ex12/ft_print_memory.c -o ./ft_print_memory.o

	${CC} -c ./main.c -o ./main.o

	${CC} ./ft_strcpy.o ./ft_strncpy.o ./ft_str_is_alpha.o ./ft_str_is_numeric.o ./ft_str_is_lowercase.o ./ft_str_is_uppercase.o ./ft_str_is_printable.o ./ft_strupcase.o ./ft_strlowcase.o ./ft_strcapitalize.o ./ft_strlcpy.o ./ft_putstr_non_printable.o ./ft_print_memory.o ./main.o -o tst

debug:
	$(MAKE) $(THIS_FILE) DEBUG="-g -D_DEBUG" all
