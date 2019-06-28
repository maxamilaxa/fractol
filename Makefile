# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/30 00:22:09 by mkopiika          #+#    #+#              #
#    Updated: 2019/04/30 00:22:14 by mkopiika         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLG_MLX = -lmlx -framework OpenGL -framework AppKit

FLG = -Wall -Wextra -Werror

LIB_DIR = ./libft/

SRC_DIR = ./src/

INC_DIR = ./inc/

OBJ_DIR = ./obj/

SRC =

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@make -C libft/
	@gcc $(FLG) $(OBJ) -o $(NAME) -L $(LIB_DIR) -lft $(FLG_MLX)

$(OBJ_DIR):
	@mkdir obj

$(OBJ_DIR)%.o: %.c
	@gcc -c $(FLG) $< -o $@ -I $(INC_DIR)

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all

vpath %.c $(SRC_DIR)
