# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: akerdeka <akerdeka@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/12/20 13:51:34 by akerdeka     #+#   ##    ##    #+#        #
#    Updated: 2020/01/28 18:23:30 by akerdeka    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

SRCS_PARSING =	$(addprefix parsing/, parsing.c)


SRCS_PATH =	srcs/


SRCS_NAME =	cub3d.c $(SRCS_PARSING)


SRCS =	$(addprefix $(SRC_PATH), $(SRCS_NAME))


OBJ_NAME =	${SRCS_NAME:.c=.o}


OBJ_PATH =	bin/


OBJ =	$(addprefix $(OBJ_PATH), $(OBJ_NAME))


HEADER =	includes/


NAME =	cub3D


CC =	cc


CFLAGS =	-Wall -Wextra -Werror -g3


RM =	rm -rf


LIBFT = libft/libft.a


all :	$(OBJ_PATH) $(LIBFT) $(NAME) includes/cub3d.h

$(LIBFT):
	make -C libft/

$(OBJ_PATH):
	@mkdir -p bin/ 2> /dev/null
	@mkdir -p bin/parsing 2> /dev/null

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c $(HEADER) Makefile includes/cub3d.h
	@gcc $(CFLAGS) -I $(HEADER) -c $< -o $@

$(NAME):	$(OBJ) $(HEADER)
	@gcc $(CFLAGS) $(LIBFT) $(OBJ) -o $(NAME)

clean : 
	@$(RM) $(OBJ_PATH) cub3D.dSYM

fclean : 	clean
	@rm -f $(NAME)

re : fclean all

.PHONY :	all clean fclean re