# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 21:22:15 by ohayek            #+#    #+#              #
#    Updated: 2023/07/27 23:16:55 by ohayek           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c init.c draw.c draw1.c ft_atoi_base.c free.c image.c \
	 get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)
SRC_BONUS = bonus/main_bonus.c bonus/init.c bonus/draw.c bonus/draw1.c bonus/ft_atoi_base.c bonus/free.c bonus/image.c bonus/rotate.c bonus/translate.c bonus/zoom_in.c bonus/zoom_out.c \
	 bonus/get_next_line.c bonus/get_next_line_utils.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)


CFLAGS = -Wall -Wextra -Werror
CC = gcc

MLX_FLAGS = -framework OpenGL -framework AppKit
MATH_FLAGS = -lm
MLX_LB	   = miniliblx/minilibx_macos/libmlx.a

LIBFT =libft/libft.a
NAME = fdf
NAME_BONUS = fdf_bonus
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX_LB)
	$(CC) $(CC_FLAGS) $(MATH_FLAGS) $(MLX_FLAGS) $(OBJ) $(LIBFT) $(MLX_LB) -o $@

$(LIBFT):
	make -C libft/ all
$(MLX_LB):
	make -C miniliblx/minilibx_macos/ all
	
$(OBJ): $(SRC) 
	$(CC) $(CC_FLAGS) -c $(SRC)

bonus: $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS) $(LIBFT) $(MLX_LB)
	$(CC) $(CC_FLAGS) $(MATH_FLAGS) $(MLX_FLAGS) $(OBJ_BONUS) $(LIBFT) $(MLX_LB) -o $(NAME_BONUS)

$(OBJ_BONUS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)
	make -C libft/ clean
	make -C miniliblx/minilibx_macos/ clean
		
fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)
	make -C libft/ fclean

re: fclean all
