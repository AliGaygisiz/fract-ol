NAME        := fractol
CC        := gcc
FLAGS    := -Wall -Wextra -Werror -g

LIBFT 		= ./libft/libft.a
SRCS        :=      ./src/mlx.c \
					./src/julia.c \
					./src/snail.c \
					./src/colors.c \
					./src/inputs.c \
					./src/mandelbrot.c \
					./main.c
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}
CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

UNAME		:=	$(shell uname)

$(NAME): ${OBJS} ${LIBFT}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@ $(MAKE) -C mlx all >/dev/null 2>&1
			@ cp ./mlx/libmlx.a .
			$(CC) $(FLAGS) -g3 -Ofast -o $(NAME) -Imlx $(OBJS) $(LIBFT) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit
			@echo "$(GREEN)$(NAME) created[0m ✔️"

$(LIBFT):
	make -C ./libft >/dev/null
all:		${NAME}

bonus: 		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ rm libmlx.a
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all bonus clean fclean re
