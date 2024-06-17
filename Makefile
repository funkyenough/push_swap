NAME = push_swap
LIBFT = libft.a
FT_PRINTF = libftprintf.a

SRCDIR = ./src
LIBFTDIR = ./libft
FT_PRINTFDIR = ./ft_printf

SRCS = $(wildcard ./$(SRCDIR)/*.c)
OBJS = $(SRCS:.c=.o)

AR = ar
ARFLAGS = rcs

CC = cc
CFLAGS = -Wall -Werror -Wextra
CSAFE = -g -fsanitize=address

RM = rm -f

ifdef WITH_SAFE
	CC += $(CSAFE)
endif

all : $(NAME)

$(NAME) : libs $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(FT_PRINTF)

libs :
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFT) .
	make -C $(FT_PRINTFDIR)
	cp $(FT_PRINTFDIR)/$(FT_PRINTF) .

$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

safe :
	make WITH_SAFE=1 all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) *.o $(LIBFT) $(FT_PRINTF)
	make fclean -C $(LIBFTDIR)
	make fclean -C $(FT_PRINTFDIR)

re: fclean all