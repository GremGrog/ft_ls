# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/28 14:21:18 by fmasha-h          #+#    #+#              #
#    Updated: 2019/05/29 18:23:16 by fmasha-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

FLAGS = -Wall -Wextra -Werror

LS_HEAD = -I ft_ls.h

PRINTF_HEAD = -I ft_printf/MainHeader/ft_printf.h

PRINTF_LIB = ft_printf/libftprintf.a

DIR_O = obj

SRCF = srcs/add_flags.c \
	   srcs/ft_ls.c \
	   srcs/lst_functions.c

OBJF = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SRCF)))

all: $(NAME)
	@true

$(DIR_O):
	@mkdir -p obj
	@mkdir -p obj/srcs

$(NAME): $(DIR_O) $(OBJF)
	@make -C ft_printf
	gcc $(FLAGS) $(OBJF) $(PRINTF_LIB) -o $(NAME)

$(DIR_O)/%.o: %.c
	gcc $(FLAGS) $(LS_HEAD) $(PRINTF_HEAD) -o $@ -c $<

clean:
	@rm -rf $(DIR_O)
	@make clean -C ft_printf

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C ft_printf

re: fclean all
