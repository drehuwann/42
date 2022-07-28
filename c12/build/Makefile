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
	${CC} -c ../ex08/ft_list_reverse.c -I./ -o ft_list_reverse.o
	${CC} -c ../ex09/ft_list_foreach.c -I./ -o ft_list_foreach.o
	${CC} -c ../ex10/ft_list_foreach_if.c -I./ -o ft_list_foreach_if.o
	${CC} -c ../ex11/ft_list_find.c -I./ -o ft_list_find.o
	${CC} -c ../ex12/ft_list_remove_if.c -I./ -o ft_list_remove_if.o
	${CC} -c ../ex13/ft_list_merge.c -I./ -o ft_list_merge.o
	${CC} -c ../ex14/ft_list_sort.c -I./ -o ft_list_sort.o

	${CC} -c ../../c07/ex00/ft_strdup.c -o ./ft_strdup.o
	${CC} -c ../../c02/ex07/ft_strupcase.c -o ./ft_strupcase.o
	${CC} -c ../../c02/ex08/ft_strlowcase.c -o ./ft_strlowcase.o
	${CC} -c ../../c03/ex00/ft_strcmp.c -o ./ft_strcmp.o
	${CC} -c ./main.c -o ./main.o

	${CC} ./ft_create_elem.o ./ft_list_push_front.o ./ft_list_size.o \
./ft_list_last.o ./ft_list_push_back.o ft_list_push_strs.o ./ft_list_clear.o \
./ft_list_at.o ./ft_list_reverse.o ./ft_list_foreach.o ./ft_list_foreach_if.o \
./ft_list_find.o ./ft_list_remove_if.o ./ft_list_merge.o ./ft_list_sort.o \
./ft_strdup.o ./ft_strupcase.o ./ft_strlowcase.o ./ft_strcmp.o ./main.o -o tst

	@echo "!! Test with : 'valgrind -q ./tst'"

debug:
	$(MAKE) clean
	$(MAKE) $(THIS_FILE) DEBUG="-g -D_DEBUG" all

clean:
	$(RM) ./*.o ./tst

re:
	$(MAKE) clean
	$(MAKE) all
