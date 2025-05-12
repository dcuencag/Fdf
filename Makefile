# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/26 13:26:17 by dancuenc          #+#    #+#              #
#    Updated: 2025/05/12 13:31:14 by dancuenc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = src/main.c src/window.c src/maping.c src/zoom.c src/move.c src/utils.c \
src/parser.c src/bresenham.c src/draw_lines.c src/colors.c src/rotate.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

INCLUDES = -Iincludes -Ilibft/includes -Iminilibx-linux -Ifdf -lft -lmlx -lXext -lX11 -lm

LIBFT_DIR = ./libft/standar
LIBFT_A = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX_A = $(MLX_DIR)/libmlx_Linux.a

LDFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lbsd -lm -L$(LIBFT_DIR) -lft

all: $(LIBFT_A) $(MLX_A) $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_A):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re