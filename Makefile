# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akerdeka <akerdeka@student.le-101.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/20 13:51:34 by akerdeka          #+#    #+#              #
#    Updated: 2020/03/09 16:52:22 by akerdeka         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

BLUE =\033[0;38;5;123m
LIGHT_PINK = \033[0;38;5;200m
PINK = \033[0;38;5;198m
DARK_BLUE = \033[1;38;5;110m
GREEN = \033[1;32;111m
LIGHT_GREEN = \033[0;38;5;121m
LIGHT_RED = \033[0;31;5;110m
FLASH_GREEN = \033[33;32m
WHITE_BOLD = \033[37m
GREY = \033[3;90m
ORANGE = \033[3;91m
YELLOW = \033[0;33m

SRCS_PARSING =	$(addprefix parsing/, parsing.c get_texture.c f_converter.c\
					c_converter.c parsing_map.c get_map.c)


SRCS_ERROR =	$(addprefix errors/, check_error.c ft_exit.c)


SRCS_CUB =	$(addprefix cub/, cub.c init_player.c raycast.c move.c\
				draw.c textures.c load_textures.c)


SRCS_PATH =	srcs/


SRCS_NAME =	cub3d.c $(SRCS_PARSING) $(SRCS_ERROR) $(SRCS_CUB)


SRCS =	$(addprefix $(SRC_PATH), $(SRCS_NAME))


OBJ_NAME =	${SRCS_NAME:.c=.o}


OBJ_PATH =	bin/


OBJ =	$(addprefix $(OBJ_PATH), $(OBJ_NAME))


HEADER =	includes/


NAME =	cub3D


CC =	cc


CFLAGS =	-Wall -Wextra -Werror -g3 #-fsanitize=address


RM =	rm -rf


LIBFT = libft/libft.a


MINILIBX = libmlx/libmlx.a

FRAMEWORK = -l mlx -framework OpenGL -framework AppKit -L libmlx -O3 -I libmlx

all :	$(OBJ_PATH) $(LIBFT) $(MINILIBX) $(NAME) includes/cub3d.h includes/keycode.h

$(LIBFT):
	make -C libft/

$(MINILIBX):
	make -C libmlx/

$(OBJ_PATH):
	@mkdir -p bin/ 2> /dev/null
	@mkdir -p bin/parsing 2> /dev/null
	@mkdir -p bin/errors 2> /dev/null
	@mkdir -p bin/cub 2> /dev/null

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c $(HEADER) Makefile includes/cub3d.h includes/keycode.h
	@gcc $(CFLAGS) -I $(HEADER) -I libmlx -c $< -o $@

$(NAME):	$(OBJ) $(HEADER)
	@gcc $(CFLAGS) $(FRAMEWORK) $(LIBFT) $(OBJ) -o $(NAME)
	@printf "	\033[2K\r$(DARK_BLUE)cube3D\t:\t$(LIGHT_GREEN)Updated\n\033[0m"

clean : 
	@$(RM) $(OBJ_PATH) cub3D.dSYM

fclean : 	clean
	@rm -f $(NAME)

re : fclean all

relib:
	@$(MAKE) fclean
	@make -C libft/ re
	@$(MAKE) all


.PHONY :	all clean fclean re relib