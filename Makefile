NAME		=	cub3D

LIBFT		=	./libft/libft.a
MLX			=	./mlx/libmlx.a
MLX_CP		=	./mlx
INC			=	includes/
SRC_DIR		=	sources/
OBJ_DIR		=	objects/

CC			=	@cc
CFLAGS		=	-Wall -Werror -Wextra -g
MLXFLAGS	=	-L ./mlx/ -lmlx -framework OpenGL -framework AppKit -lz
ifeq ($(shell uname), Linux)
	MLXFLAGS	=	-Iminilibx-linux -lXext -lX11 -lm -lz
	MLX = ./mlx_linux/libmlx.a
	MLX_CP		=	./mlx_linux
	INC = -I. -Iincludes -Imlx_linux
	M = mlx_linux
endif
RM			=	@rm -f

CUB_DIR	=	$(SRC_DIR)main.c \
			$(SRC_DIR)cub_utils/error.c \

SRCS	=	$(CUB_DIR)

OBJS	=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT) $(MLX)
		@echo "\033[1;32mMake .o and executable.\033[0m"
		@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
		@make -s -C ./libft

$(MLX):
		@make -s -C $(MLX_CP)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

clean:
		$(RM) -r $(OBJ_DIR)
		@make -s clean -C ./libft
		@make -s clean -C $(MLX_CP)
		@echo "\033[1;31mClean .o files.\033[0m"

fclean:		clean
		$(RM) $(NAME)
		@make -s fclean -C ./libft
		@echo "\033[1;31mClean executable/s.\033[0m"

re:		fclean all

.PHONY:		clean fclean re
