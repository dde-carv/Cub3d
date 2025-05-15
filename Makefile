NAME		=	cub3D

LIBFT		=	./libft/libft.a
MLX			=
INC			=	includes/
SRC_DIR		=	sources/
OBJ_DIR		=	objects/

CC			=	@cc
CFLAGS		=	-Wall -Werror -Wextra -g
MLXFLAGS	=	-L ../mlx/ -lmlx -framework OpenGL -framework AppKit -lz
ifeq ($(shell uname), Linux)
	MLXFLAGS	=	-L ./mlx_linux/ -lmlx -Imlx -lXext -lX11
	MLX = mlx_linux/libmlx.a
	INC = -I. -Iincludes -Imlx_linux
	M = mlx_linux
endif
RM			=	@rm -f

CUB_DIR	=	$(SRC_DIR)builtins/main.c \

SRCS	=	$(CUB_DIR)

OBJS	=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
		@echo "\033[1;32mMake .o and executable.\033[0m"
		@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
		@make -s -C ./libft

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

clean:
		$(RM) -r $(OBJ_DIR)
		@make -s clean -C ./libft
		@echo "\033[1;31mClean .o files.\033[0m"

fclean:		clean
		$(RM) $(NAME)
		@make -s fclean -C ./libft
		@echo "\033[1;31mClean executable/s.\033[0m"

re:		fclean all

.PHONY:		clean fclean re
