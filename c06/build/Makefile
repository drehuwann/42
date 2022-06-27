THIS_FILE := $(lastword $(MAKEFILE_LIST))
CC := gcc -Wall -Wextra -Werror $(DEBUG)
RM := rm -f

all:
	${CC} ../ex00/ft_print_program_name.c -o ./ft_print_program_name
	${CC} ../ex01/ft_print_params.c -o ./ft_print_params
	${CC} ../ex02/ft_rev_params.c -o ./ft_rev_params
	${CC} ../ex03/ft_sort_params.c -o ./ft_sort_params

debug:
	$(MAKE) $(THIS_FILE) DEBUG="-g -D_DEBUG" all

clean:
	$(RM) *.o ft_print_program_name ft_print_params ft_rev_params ft_sort_params
