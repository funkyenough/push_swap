NAME = push_swap
LIBFT = libft.a

SRCDIR = ./src
LIBFTDIR = ./libft
SRCS = $(wildcard ./$(SRCDIR)/*.c)
OBJS = $(SRCS:.c=.o)

AR = ar
ARFLAGS = rcs

CC = cc
CFLAGS = -Wall -Werror -Wextra

RM = rm -f


all : $(NAME)

$(NAME) : $(OBJS)
	make bonus -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFT) .
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) main.o
	make fclean -C $(LIBFTDIR)

re: fclean all