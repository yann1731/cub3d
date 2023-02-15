SRCS	=	main.c utils.c parse.c keypress.c scaling_utils.c render_utils.c dda_routine.c dda.c move_utils.c \
			texture_utils.c init_utils.c mem_utils.c accel_utils.c move.c mem_misc.c render_utils2.c \
			validation_map.c set_data.c parsing_utils.c tokenization.c axis.c

SRCS_BONUS	=	main.c dda_bonus.c dda_routine_bonus.c init_utils_bonus.c keypress_bonus.c map_utils_bonus.c map_utils2_bonus.c \
				mem_utils_bonus.c move_bonus.c parse_bonus.c render_utils_bonus.c texture_bonus.c scaling_utils.c \
				misc_utils.c utils.c move_utils.c accel_utils.c mem_misc.c render_utils_bonus2.c \
				validation_map_bonus.c set_data_bonus.c parsing_utils_bonus.c tokenization_bonus.c axis_bonus.c
%.o: %.c
	$(CC) ${CFLAGS} -I/usr/include -Imlx-linux -O3 -c $< -o $@

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

NAME = project.a

PROGRAM = cub3d

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -Rf

MLX_MAC = -Lmlx-mac -lmlx -framework OpenGL -framework AppKit

MLX_LIN = -I./mlx-linux -L./mlx-linux -lmlx -L. -lX11 -lXext -lm -lbsd

OS_NAME := $(shell uname -s | tr A-Z a-z)

ifeq ($(OS_NAME), linux)
	MLX = ${MLX_LIN}
	MLX_FOL = mlx-linux
else
	MLX = ${MLX_MAC}
	MLX_FOL = mlx-mac
endif

${NAME}: ${OBJS} main.c
	make -C libft/
	cp libft/libft.a lib${NAME}
	ar rcs lib${NAME} ${OBJS}
	make -C ${MLX_FOL}
	${CC} ${CFLAGS} main.c -L. -l$(basename ${NAME}) ${MLX} -o ${PROGRAM}

all: ${NAME}

bonus: ${OBJS_BONUS}
	make -C libft/
	cp libft/libft.a lib${NAME}
	ar rcs lib${NAME} ${OBJS_BONUS}
	make -C ${MLX_FOL}
	${CC} ${CFLAGS} main.c -L. -l$(basename ${NAME}) ${MLX} -o ${PROGRAM}

norminette:
	norminette ${SRCS}

normbonus:
	norminette ${SRCS_BONUS}

clean:
	${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	@make fclean -C libft/
	@make clean -C ${MLX_FOL}/
	${RM} lib${NAME} ${PROGRAM}

re: fclean all

.PHONY: all bonus clean fclean re
