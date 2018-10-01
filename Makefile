# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allallem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 16:48:55 by allallem          #+#    #+#              #
#    Updated: 2017/12/20 10:30:38 by allallem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fillit

SRC=		main.c ft_put_in_memory.c ft_check_all.c ft_get_form_tab.c ft_recup_piece.c ft_placepiece.c ft_clean.c ft_put.c

OBJ=		$(SRC:.c=.o)

CC=		gcc

CFLAGS=	-Werror -Wextra -Wall -Ilibft/

DEL=	rm -f

LIB= libft/libft.a

all		:	$(NAME)

re		:	fclean all

$(NAME)	:	$(OBJ)
		@make -C ./libft
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)
fclean	:	clean
		@$(DEL) $(NAME)
		@make -C ./libft fclean

clean	:
		@$(DEL) $(OBJ)
		@make -C ./libft clean

.PHONY: all clean fclean re
