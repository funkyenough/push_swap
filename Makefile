# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 20:01:16 by yinhong           #+#    #+#              #
#    Updated: 2024/07/07 09:36:49 by yinhong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = libft.a
FT_PRINTF = libftprintf.a

SRCDIR = ./src
OBJDIR = ./obj
LIBFTDIR = ./libft
FT_PRINTFDIR = ./ft_printf

SRCS = $(shell find $(SRCDIR) -type f -name '*.c')
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
	cp $(NAME) ./push_swap_visualizer

$(NAME) : libs $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(OBJDIR)/$(LIBFT) $(OBJDIR)/$(FT_PRINTF)

libs : | $(OBJDIR)
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFT) $(OBJDIR)
	make -C $(FT_PRINTFDIR)
	cp $(FT_PRINTFDIR)/$(FT_PRINTF) $(OBJDIR)

$(OBJDIR)/%.o : $(SRCDIR)/%.c | $(OBJDIR)
	@mkdir -p $(@D)
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