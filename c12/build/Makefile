THIS_FILE := $(lastword $(MAKEFILE_LIST))
CC := gcc -Wall -Wextra -Werror $(DEBUG)
RM := rm -f

all:
	${CC} -c ../ex00/ft_create_elem.c -I./ -o ft_create_elem.o
	${CC} -c ../ex01/ft_list_push_front.c -I./ -o ft_list_push_front.o
	${CC} -c ../ex02/ft_list_size.c -I./ -o ft_list_size.o
	${CC} -c ../ex03/ft_list_last.c -I./ -o ft_list_last.o
	${CC} -c ../ex04/ft_list_push_back.c -I./ -o ft_list_push_back.o
	${CC} -c ../ex05/ft_list_push_strs.c -I./ -o ft_list_push_strs.o
	${CC} -c ../ex06/ft_list_clear.c -I./ -o ft_list_clear.o
	${CC} -c ../ex07/ft_list_at.c -I./ -o ft_list_at.o

	${CC} -c ../../c07/ex00/ft_strdup.c -o ./ft_strdup.o
	${CC} -c ./main.c -o ./main.o

	${CC} ./ft_create_elem.o ./ft_list_push_front.o ./ft_list_size.o \
./ft_list_last.o ./ft_list_push_back.o ft_list_push_strs.o ./ft_list_clear.o \
./ft_list_at.o ./ft_strdup.o ./main.o -o tst

	echo "!! Test with : 'valgrind -q ./tst'"

debug:
	$(MAKE) clean
	$(MAKE) $(THIS_FILE) DEBUG="-g -D_DEBUG" all

clean:
	$(RM) ./*.o ./tst

re:
	$(MAKE) clean
	$(MAKE) all
