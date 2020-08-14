# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/20 13:51:34 by akerdeka          #+#    #+#              #
#    Updated: 2020/08/14 14:21:22 by akerdeka         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

BLUE = \033[0;38;5;123m
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
					c_converter.c parsing_map.c get_map.c rfc_checker.c\
					verrif_map.c)


SRCS_ERROR =	$(addprefix errors/, check_error.c ft_exit.c)


SRCS_CUB =	$(addprefix cub/, cub.c init_player.c raycast.c move.c\
				draw.c textures.c load_textures.c sprites_raycast.c\
				draw_sprites.c save_bitmap.c)



SRCS_PATH =	srcs/


SRCS_NAME =	cub3d.c $(SRCS_PARSING) $(SRCS_ERROR) $(SRCS_CUB)


SRCS =	$(addprefix $(SRCS_PATH), $(SRCS_NAME))


OBJ =	libmlx/libmlx.a libft/libft.a $(SRCS:.c=.o)


HEADERS =	includes/*.h


NAME =	Cub3D


CC =	cc


CFLAGS = -Wall -Werror -Wextra -O3 #-fsanitize=leak -g3


RM =	rm -rf


MINILIBX_PATH =	./libmlx/


MLX =	-Llibft -lft -L libmlx -lmlx -lbsd -lXext -lX11 -lm


LIBFT_PATH = ./libft/


all :	libft_all minilibx_all $(NAME)


$(NAME) :	$(OBJ)
					@$(CC) $(CFLAGS) -o $@ $(OBJ) $(MLX)
			@echo "\033[38;2;153;102;255;1m######################################"
			@echo "\033[38;2;153;102;255;1m#\033[38;2;0;204;0;1m\tCompiling $(NAME)...   \033[38;2;153;102;255;1m\t     #\n#\033[38;2;0;204;0;1m\t\tDone\t\t     \033[0m\033[38;2;153;102;255;1m#"
			@echo "\033[38;2;153;102;255;1m######################################\033[0m"


%.o: %.c $(HEADERS)
			@$(CC) $(CFLAGS) -o $@ -c $<
			@echo "\033[38;2;255;204;0;1mCompiling object $@...\nDone\033[0m"


clean :	libft_clean minilibx_clean
			@$(RM) -f $(OBJ)
			@echo "\033[38;2;255;51;0;1mDeleting objects file...\nDone"


fclean :	libft_fclean clean
				@rm -f $(NAME)
				@echo "Deleting $(NAME)...\nDone\033[0m"

				
re :	fclean all

libft_all :
				make -C $(LIBFT_PATH) all

libft_clean :
				@make -C $(LIBFT_PATH) clean


libft_fclean :
				make -C $(LIBFT_PATH) fclean


minilibx_all :
				@make -C $(MINILIBX_PATH) all


minilibx_clean :
				@make -C $(MINILIBX_PATH) clean


relib:
	@$(MAKE) fclean
	@make -C libft/ re
	@$(MAKE) all


.PHONY :	all clean fclean re relib