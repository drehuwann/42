CC = gcc
CFLAGS = -Wall  -Wextra -Werror
SRCDIR = ./srcs
OBJDIR = $(SRCDIR)
HEADER = -Iincludes
AR = ar rcs
RM = rm -f

SRCS :=	$(wildcard $(SRCDIR)/*.c)
OBJS := $(patsubst %.c, %.o, $(SRCS))

all: libft.a

libft.a: $(OBJS)
	$(AR) $@ $(OBJS) 

.c.o:
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean:
	$(RM) $(SRCDIR)/*.o

fclean:
	$(MAKE) clean
	$(RM) ./libft.a

re:	
	$(MAKE) fclean
	$(MAKE) all
