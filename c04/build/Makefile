THIS_FILE := $(lastword $(MAKEFILE_LIST))
CC := gcc -Wall -Wextra -Werror $(DEBUG)

all:
	${CC} -c ../ex00/ft_strlen.c -o ./ft_strlen.o
	${CC} -c ../ex01/ft_putstr.c -o ./ft_putstr.o
	${CC} -c ../ex02/ft_putnbr.c -o ./ft_putnbr.o
	${CC} -c ../ex03/ft_atoi.c -o ./ft_atoi.o
	${CC} -c ../ex04/ft_putnbr_base.c -o ./ft_putnbr_base.o
	${CC} -c ../ex05/ft_atoi_base.c -o ./ft_atoi_base.o

	${CC} -c ./main.c -o ./main.o

	${CC} ./ft_strlen.o ./ft_putstr.o ./ft_putnbr.o ./ft_atoi.o ./ft_putnbr_base.o ./ft_atoi_base.o ./main.o -o tst

debug:
	$(MAKE) $(THIS_FILE) DEBUG="-g -D_DEBUG" all
