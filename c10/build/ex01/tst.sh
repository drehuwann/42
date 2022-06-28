#!/bin/sh
make re
STACKSIZE=$(ulimit -Ss)
ulimit -Ss 30
./ft_cat ft_cat.c ft_cat.h ft_cat.o ft_cat Makefile
ulimit -Ss $STACKSIZE
