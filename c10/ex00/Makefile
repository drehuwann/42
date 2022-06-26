TARGET = ft_display_file
CC = gcc
CFLAGS = -Wall  -Wextra -Werror
SRCDIR = .
HEADER = -I.
RM = rm -f

SRCS :=	$(wildcard $(SRCDIR)/$(TARGET).c)
OBJS := $(patsubst %.c, %.o, $(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) 

.c.o:
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean:
	$(RM) $(SRCDIR)/*.o

fclean:
	$(MAKE) clean
	$(RM) $(TARGET)

re:	
	$(MAKE) fclean
	$(MAKE) all
