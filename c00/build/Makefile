THIS_FILE := $(lastword $(MAKEFILE_LIST))
CC := gcc -Wall -Wextra -Werror $(DEBUG)

all:
	${CC} -c ../ex00/ft_putchar.c -o ./ft_putchar.o
	${CC} -c ../ex01/ft_print_alphabet.c -o ./ft_print_alphabet.o
	${CC} -c ../ex02/ft_print_reverse_alphabet.c -o ./ft_print_reverse_alphabet.o
	${CC} -c ../ex03/ft_print_numbers.c -o ./ft_print_numbers.o
	${CC} -c ../ex04/ft_is_negative.c -o ./ft_is_negative.o
	${CC} -c ../ex05/ft_print_comb.c -o ./ft_print_comb.o
	${CC} -c ../ex06/ft_print_comb2.c -o ./ft_print_comb2.o
	${CC} -c ../ex07/ft_putnbr.c -o ./ft_putnbr.o
	${CC} -c ../ex08/ft_print_combn.c -o ./ft_print_combn.o
	${CC} -c ./main.c -o ./main.o
	${CC} ./ft_putchar.o ./ft_print_alphabet.o ./ft_print_reverse_alphabet.o ./ft_print_numbers.o ./ft_is_negative.o ./ft_print_comb.o ./ft_print_comb2.o ./ft_putnbr.o ./ft_print_combn.o ./main.o -o tst

debug:
	$(MAKE) $(THIS_FILE) DEBUG="-g -D_DEBUG" all
