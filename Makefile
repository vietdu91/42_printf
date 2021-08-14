NAME	= libftprintf.a

SRCS_C	= 	big_regle_baton.c \
			checkpoint.c \
			flags_factory.c \
			flags_gestion.c \
			ft_printf.c \
			highways.c \
			inspection.c \
			print_c.c \
			print_d_and_i.c \
			print_hexa_utils.c \
			print_nbr_utils.c \
			print_p.c \
			print_percent.c \
			print_s.c \
			print_str_utils.c \
			print_u.c \
			print_uns_utils.c \
			print_x.c \

DIR_S	= srcs

DIR_O	= obj

HEADER	= includes

OBJS	= ${SRCS_C:.c=.o}
OBJS	:= $(addprefix $(DIR_O)/,${OBJS})

$(NAME):	${OBJS}
#			@make -C libft
#			@mv libft/libft.a ./$(NAME)
			@ar rc ${NAME} ${OBJS}
			@ranlib ${NAME} 
			@echo "\n La vie passe, la moulinette trepasse."

$(DIR_O)/%.o:		${DIR_S}/%.c
					@mkdir -p obj
					gcc -Wall -Werror -Wextra -I ${HEADER} -o $@ -c $<

norme:		norminette {SRCS}
			norminette {HEADER}

all:		${NAME}

bonus:		${NAME}

clean:
			rm -f ${OBJS}

fclean:
			rm -f ${OBJS}
			rm -f ${NAME}

re:			fclean all

.PHONY: 	bonus all clean fclean re
