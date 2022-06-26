THIS_FILE := $(lastword $(MAKEFILE_LIST))
CC := gcc -Wall -Wextra -Werror $(DEBUG)

all:
	${CC} -c ../../ex02/ft_split.c -I. -o ./ft_split.o
	${CC} -c ./main.c -o ./main.o

	${CC} ./ft_split.o main.o -o tst

debug:
	$(MAKE) $(THIS_FILE) DEBUG="-g -D_DEBUG" all

clean:
	rm -f *.o tst

