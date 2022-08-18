THIS_FILE := $(lastword $(MAKEFILE_LIST))
CC := gcc -Wall -Wextra -Werror $(DEBUG) -I../ex00
RM := rm -f

all:	
	${CC} -o rush-01 ../ex00/*.c

debug:
	$(MAKE) clean
	$(MAKE) $(THIS_FILE) DEBUG="-g -D_DEBUG" all

clean:
	$(RM) ./*.o ./rush-01

re:
	$(MAKE) clean
	$(MAKE) all
