TARGET = ft_cat
CC = gcc
CFLAGS = -Wall  -Wextra -Werror $(DEBUG)
BUFSIZE = -DBUFFERSIZE=16384
# experiment with BUFFERSIZE value, running ../build/ex01/tst.sh
SRCDIR = .
HEADER = -I.
RM = rm -f

SRCS :=	$(wildcard $(SRCDIR)/$(TARGET).c)
OBJS := $(patsubst %.c, %.o, $(SRCS))

THIS_FILE := $(lastword $(MAKEFILE_LIST))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(BUFSIZE) -o $@ $(OBJS) 

.c.o:
	$(CC) $(CFLAGS) $(HEADER) $(BUFSIZE) -c $< -o $@

debug:
	$(MAKE) $(THIS_FILE) DEBUG="-g -D_DEBUG" all

clean:
	$(RM) $(SRCDIR)/*.o

fclean:
	$(MAKE) clean
	$(RM) $(TARGET)

re:	
	$(MAKE) fclean
	$(MAKE) all
