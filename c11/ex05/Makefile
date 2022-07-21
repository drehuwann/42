MAKEFLAGS = --quiet -j$(nproc)
TARGET = do_op
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
	$(RM) $(TARGET)

re:	
	$(MAKE) clean
	$(MAKE) all

debug:
	$(MAKE) clean
	$(MAKE) $(THIS_FILE) DEBUG="-g -D_DEBUG" all
