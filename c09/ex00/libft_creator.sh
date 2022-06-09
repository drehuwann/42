#!/bin/sh
#########
# USAGE : ./libft_creator.sh [OBJDIR] [LIBDIR]
# default  : LIBDIR = OBJDIR  if OBJDIR only is given
#########
#

CC=gcc
CFLAGS='-Wall -Wextra -Werror'
if [ $1 ]; then
    OBJDIR=$1
    echo compiling object files under $1
    else OBJDIR=.
fi

if [ ! $2 ]; then
	LIBDIR=$OBJDIR
	else LIBDIR=$2
fi

for FILE in `ls *.c`
do
    echo compiling $FILE 
    $CC $CFLAGS -c $FILE -o $OBJDIR/$FILE.o
done

echo linking $LIBDIR/libft.a
ar rcs $LIBDIR/libft.a $OBJDIR/*.o
rm $OBJDIR/*.o

