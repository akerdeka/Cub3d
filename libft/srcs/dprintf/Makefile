# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akerdeka <akerdeka@student.le-101.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/20 13:51:34 by akerdeka          #+#    #+#              #
#    Updated: 2020/02/17 15:14:03 by akerdeka         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


SRCS =	algo.c\
		convert.c\
		convert_c.c\
		convert_d.c\
		convert_p.c\
		convert_percent.c\
		convert_s.c\
		convert_star.c\
		convert_u.c\
		convert_x.c\
		feild.c\
		flag_gest.c\
		ft_dprintf.c\
		gest_precision.c\
		libft/ft_atoi.c\
		libft/ft_bzero.c\
		libft/ft_calloc.c\
		libft/ft_isalnum.c\
		libft/ft_isalpha.c\
		libft/ft_isascii.c\
		libft/ft_isdigit.c\
		libft/ft_isprint.c\
		libft/ft_itoa.c\
		libft/ft_itoa_base.c\
		libft/ft_itoa_base_maj.c\
		libft/ft_memccpy.c\
		libft/ft_memchr.c\
		libft/ft_memcmp.c\
		libft/ft_memcpy.c\
		libft/ft_memmove.c\
		libft/ft_memset.c\
		libft/ft_putchar_fd.c\
		libft/ft_putendl_fd.c\
		libft/ft_putnbr_fd.c\
		libft/ft_putstr_fd.c\
		libft/ft_split.c\
		libft/ft_strchr.c\
		libft/ft_strclen.c\
		libft/ft_strcpy.c\
		libft/ft_strdup.c\
		libft/ft_strjoin.c\
		libft/ft_strfjoin.c\
		libft/ft_strlcat.c\
		libft/ft_strlcpy.c\
		libft/ft_strlen.c\
		libft/ft_strmapi.c\
		libft/ft_strncmp.c\
		libft/ft_strndup.c\
		libft/ft_strnstr.c\
		libft/ft_strrchr.c\
		libft/ft_strtrim.c\
		libft/ft_substr.c\
		libft/ft_tolower.c\
		libft/ft_toupper.c\
		libft/ft_uitoa.c\

OBJ =	$(SRCS:.c=.o)


HEADER =	libftdprintf.h


NAME =	libftdprintf.a


CC =	cc


CFLAGS =	-Wall -Wextra -Werror -g3


RM =	rm -rf


all :	$(NAME)


$(NAME):	$(OBJ) $(HEADER)
	@ar rc $(NAME) $(OBJ)
	@echo "\033[38;2;153;102;255;1m######################################"
	@echo "\033[38;2;153;102;255;1m#\033[38;2;0;204;0;1m\tCompiling $(NAME)...   \033[38;2;153;102;255;1m#\n#\033[38;2;0;204;0;1m\t\tDone\t\t     \033[0m\033[38;2;153;102;255;1m#"
	@echo "\033[38;2;153;102;255;1m######################################\033[0m"

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo "\033[38;2;255;204;0;1mCompiling object $@...\nDone\033[0m"

clean : 
	@$(RM) -f $(OBJ)

fclean : 	clean
	@rm -f $(NAME)

re : fclean all

.PHONY :	all clean fclean re