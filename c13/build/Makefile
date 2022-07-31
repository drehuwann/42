THIS_FILE := $(lastword $(MAKEFILE_LIST))
CC := gcc -Wall -Wextra -Werror $(DEBUG)
RM := rm -f

all:
	${CC} -c ../ex00/btree_create_node.c -I./ -o btree_create_node.o
	${CC} -c ../ex01/btree_apply_prefix.c -I./ -o btree_apply_prefix.o
	${CC} -c ../ex02/btree_apply_infix.c -I./ -o btree_apply_infix.o
	${CC} -c ../ex03/btree_apply_suffix.c -I./ -o btree_apply_suffix.o
	${CC} -c ../ex04/btree_insert_data.c -I./ -o btree_insert_data.o
	${CC} -c ./main.c -o ./main.o

	${CC} -c ../../c07/ex00/ft_strdup.c -o ./ft_strdup.o
	${CC} -c ../../c03/ex00/ft_strcmp.c -o ./ft_strcmp.o

	${CC} ./btree_create_node.o ./btree_apply_prefix.o \
./btree_apply_infix.o ./btree_apply_suffix.o ./btree_insert_data.o \
./ft_strdup.o ./ft_strcmp.o ./main.o -o tst

	@echo "!! Test with : 'valgrind -q ./tst'"

debug:
	$(MAKE) clean
	$(MAKE) $(THIS_FILE) DEBUG="-g -D_DEBUG" all

clean:
	$(RM) ./*.o ./tst

re:
	$(MAKE) clean
	$(MAKE) all
