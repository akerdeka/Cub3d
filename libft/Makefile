NAME = libft.a

HEADER = includes/

FLAG = -Wall -Wextra -Werror

SRCS_LIBFT =	$(addprefix ./, ft_strndup.c ft_strtok.c ft_isalnum.c\
					ft_isprint.c ft_memcmp.c ft_putchar_fd.c ft_split.c\
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c\
					ft_itoa.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c\
					ft_strlcpy.c ft_strnstr.c ft_tolower.c ft_bzero.c\
					ft_isascii.c ft_memccpy.c ft_memmove.c ft_putnbr_fd.c\
					ft_strdup.c ft_strlen.c ft_strrchr.c ft_toupper.c\
					ft_calloc.c ft_isdigit.c ft_memchr.c ft_memset.c ft_putstr_fd.c\
					ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_strfjoin.c get_next_line.c\
					ft_itoa_base.c ft_itoa_base_maj.c ft_uitoa.c)

SRCS_PRINTF =	$(addprefix Printf/, algo.c\
					convert.c convert_c.c convert_d.c\
					convert_p.c convert_percent.c convert_s.c\
					convert_star.c convert_u.c convert_x.c\
					feild.c flag_gest.c ft_printf.c gest_precision.c)

SRCS_NAME =	$(SRCS_LIBFT) $(SRCS_PRINTF)


SRCS_PATH =	srcs/


SRCS =	$(addprefix $(SRCS_PATH), $(SRCS_NAME))


OBJS_PATH =	bin/


OBJS_NAME =	${SRCS_NAME:.c=.o}


OBJS =	$(addprefix $(OBJS_PATH), $(OBJS_NAME))


all: $(OBJS_PATH) $(NAME)

$(NAME):	$(OBJS) $(HEADER)
	ar rcs $(NAME) $(OBJS)

$(OBJS_PATH):
	@mkdir -p bin/ 2> /dev/null
	@mkdir -p bin/Printf 2> /dev/null
	@mkdir -p bin/Get_Next_Line 2> /dev/null

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(HEADER) Makefile
	@gcc $(FLAG) -g3 -I ${HEADER} -c $< -o $@

clean:
	rm -rf $(OBJS_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all


.PHONY:
	all clean fclean re
