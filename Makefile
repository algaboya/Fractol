# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 19:34:54 by algaboya          #+#    #+#              #
#    Updated: 2024/07/11 16:39:06 by algaboya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

SRC = main.c utils.c str_utils.c render.c math_utils.c init.c events.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ) fractol.h Makefile
	cc $(CFLAGS) $(OBJ) $(MLXFLAGS) -o $(NAME) 

clean:
	rm -f $(OBJ) $(BNOBJ)

fclean:clean
	rm -f $(NAME)

re:fclean all

.PHONY: all clean fclean re
