NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -I./minilibx-linux -L./minilibx-linux -lmlx -lXext -lX11 -lm

SRC_DIR = src/
SRC = main.c map.c window.c ingame.c player_move.c map_check.c\
	check_walls.c pathcheck.c
OBJ_DIR = objs/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

all: libft printf $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS) libft/*.o ft_printf/*.o

libft:
	@make -C libft/

printf:
	@make -C ft_printf/

clean:
	rm -f $(OBJ)
	@make -C libft/ clean
	@make -C ft_printf/ clean
	rm -d $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: all libft clean fclean re