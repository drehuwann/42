TARGET = ft_hexdump
CC = gcc
CFLAGS = -Wall  -Wextra -Werror $(DEBUG)
SRCDIR = .
HEADER = -I.
RM = rm -f

SRCS :=	$(wildcard $(SRCDIR)/$(TARGET).c)
OBJS := $(patsubst %.c, %.o, $(SRCS))

THIS_FILE := $(lastword $(MAKEFILE_LIST))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) 

.c.o:
	$(CC) $(CFLAGS) $(HEADER) $(BUFSIZE) -c $< -o $@

clean:
	$(RM) $(SRCDIR)/*.o

fclean:
	$(MAKE) clean
	$(RM) $(TARGET)

re:	
	$(MAKE) fclean
	$(MAKE) all

debug:
	$(MAKE) fclean
	$(MAKE) $(THIS_FILE) DEBUG="-g -D_DEBUG" all
