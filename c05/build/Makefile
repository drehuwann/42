THIS_FILE := $(lastword $(MAKEFILE_LIST))
CC := gcc -Wall -Wextra -Werror $(DEBUG)

all:
	${CC} -c ../ex00/ft_iterative_factorial.c -o ./ft_iterative_factorial.o
	${CC} -c ../ex01/ft_recursive_factorial.c -o ./ft_recursive_factorial.o
	${CC} -c ../ex02/ft_iterative_power.c -o ./ft_iterative_power.o
	${CC} -c ../ex03/ft_recursive_power.c -o ./ft_recursive_power.o
	${CC} -c ../ex04/ft_fibonacci.c -o ./ft_fibonacci.o
	${CC} -c ../ex05/ft_sqrt.c -o ./ft_sqrt.o
	${CC} -c ../ex06/ft_is_prime.c -o ./ft_is_prime.o
	${CC} -c ../ex07/ft_find_next_prime.c -o ./ft_find_next_prime.o
	${CC} -c ../ex08/ft_ten_queens_puzzle.c -o ./ft_ten_queens_puzzle.o

	${CC} -c ./main.c -o ./main.o

	${CC} ./ft_iterative_factorial.o ./ft_recursive_factorial.o ./ft_iterative_power.o ./ft_recursive_power.o ./ft_fibonacci.o ./ft_sqrt.o ./ft_is_prime.o ./ft_find_next_prime.o ./ft_ten_queens_puzzle.o ./main.o -o tst

debug:
	$(MAKE) $(THIS_FILE) DEBUG="-g -D_DEBUG" all
