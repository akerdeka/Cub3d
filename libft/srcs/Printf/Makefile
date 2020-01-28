# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: akerdeka <akerdeka@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/12/20 13:51:34 by akerdeka     #+#   ##    ##    #+#        #
#    Updated: 2020/01/28 16:02:01 by akerdeka    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
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
		ft_printf.c\
		gest_precision.c\

OBJ =	$(SRCS:.c=.o)


HEADER =	libftprintf.h


NAME =	libftprintf.a


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