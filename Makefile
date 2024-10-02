NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f
MKDIR = mkdir -p

OBJDIR = objects

FILES = ft_printf_select1 \
		ft_printf_select2 \
		ft_printf_utils \
		ft_printf

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(FILES)))

$(OBJDIR)/%.o: %.c
	$(MKDIR) $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re