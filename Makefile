Name = libftprintf.a
CC = gcc -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f
MKDIR = mkdir -p

FILES = ft_printf_select1 \
		ft_printf_select2 \
		ft_printf_utils \
		ft_printf

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(FILES)))

$(OBJDIR)/%.o: %.c
	$(MKDIR) $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<