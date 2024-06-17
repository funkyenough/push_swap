NAME = push_swap
LIBFT = libft.a
FT_PRINTF = libftprintf.a

SRCDIR = ./src
OBJDIR = ./obj
LIBFTDIR = ./libft
FT_PRINTFDIR = ./ft_printf

SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

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
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(OBJDIR)/$(LIBFT) $(OBJDIR)/$(FT_PRINTF)

libs : | $(OBJDIR)
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFT) $(OBJDIR)
	make -C $(FT_PRINTFDIR)
	cp $(FT_PRINTFDIR)/$(FT_PRINTF) $(OBJDIR)

$(OBJDIR)/%.o : $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR) :
	mkdir -p $(OBJDIR)

safe :
	make WITH_SAFE=1 all

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME) *.o $(LIBFT) $(FT_PRINTF)
	make fclean -C $(LIBFTDIR)
	make fclean -C $(FT_PRINTFDIR)

re: fclean all