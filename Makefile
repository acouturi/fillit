# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acouturi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 14:51:13 by acouturi          #+#    #+#              #
#    Updated: 2017/11/29 16:43:54 by acouturi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = ft_affiche.c ft_makemap.c ft_open.c ft_optipose.c ft_splitchar.c \
	  ft_valide.c main.c

LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

INCL = -I.

CFLAGS = -Werror -Wall -Wextra

# Colors
_GREY	= "\033[0;30m"
_RED	= "\033[0;31m"
_GREEN	= "\033[0;32m"
_YELLOW	= "\033[0;33m"
_BLUE	= "\033[0;34m"
_PURPLE	= "\033[0;35m"
_CYAN	= "\033[0;36m"
_WHITE	= "\033[0;37m"
_NONE	= "\033[0m"

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	@echo $(_GREEN)" [OK]	"$(_YELLOW) "Created :	" $(_NONE) $(NAME)
	@gcc $(CFLAGS) -o $(NAME) $(SRC) $(LIBFT)
	@echo $(_GREEN) "DONE"

%.o : %.c
	@echo $(_GREEN)" [OK]	"$(_YELLOW) "Compiling :	" $(_NONE) $^
	@gcc $(CFLAGS) -o $@ -c $<

clean: cleano
	@make clean -C libft

cleano :
	@echo $(_RED) "Remove :" $(OBJ)
	@/bin/rm -f $(OBJ)
	@echo $(_GREEN) "DONE"

fclean: cleano
	@make fclean -C libft
	@echo $(_RED) "Remove :" $(NAME)
	@/bin/rm -f $(NAME)
	@echo $(_GREEN) "DONE"

re: fclean all

exe: all clean
