THIS_FILE := $(lastword $(MAKEFILE_LIST))
CC := gcc -Wall -Wextra -Werror $(DEBUG)
RM := rm -f

all:	ex00 ex01 ex02 ex03 ex04
	${CC} ./ft_putchar.o ./rush00.o ./main.o -o tst0
	${CC} ./ft_putchar.o ./rush01.o ./main.o -o tst1
	${CC} ./ft_putchar.o ./rush02.o ./main.o -o tst2
	${CC} ./ft_putchar.o ./rush03.o ./main.o -o tst3
	${CC} ./ft_putchar.o ./rush04.o ./main.o -o tst4

ex00:
	${CC} -c ../ex00/ft_putchar.c -I./ -o ft_putchar.o
	${CC} -c ../ex00/rush00.c -o ./rush00.o
	${CC} -c ../ex00/main.c -o ./main.o

ex01:	ex00
	${CC} -c ../ex00/rush01.c -o ./rush01.o

ex02:	ex00
	${CC} -c ../ex00/rush02.c -o ./rush02.o

ex03:	ex00
	${CC} -c ../ex00/rush03.c -o ./rush03.o

ex04:	ex00
	${CC} -c ../ex00/rush04.c -o ./rush04.o

debug:
	$(MAKE) clean
	$(MAKE) $(THIS_FILE) DEBUG="-g -D_DEBUG" all

clean:
	$(RM) ./*.o ./tst*

re:
	$(MAKE) clean
	$(MAKE) all
