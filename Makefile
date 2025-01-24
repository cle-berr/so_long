NAME = so_long
NAME_BONUS = so_long_bonus
CC = cc
FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -I./minilibx-linux -L./minilibx-linux -lmlx -lXext -lX11 -lm

SRC = src/main.c src/map.c src/window.c src/ingame.c src/player_move.c src/map_check.c \
	  src/check_walls.c src/pathcheck.c src/map_check_utils.c

SRC_BONUS = src_bonus/main_bonus.c src_bonus/map_bonus.c \
			src_bonus/window_bonus.c src_bonus/ingame_bonus.c \
			src_bonus/player_move_bonus.c src_bonus/map_check_bonus.c \
			src_bonus/check_walls_bonus.c src_bonus/pathcheck_bonus.c \
			src_bonus/map_check_utils_bonus.c src_bonus/player_move_utils_bonus.c \
			src_bonus/start_screen.c

all: libft printf $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -o $(NAME) $(SRC) $(MLX_FLAGS) libft/*.o ft_printf/*.o
	@echo "Compiled $(NAME)"

bonus: libft printf $(NAME_BONUS)

$(NAME_BONUS):
	@$(CC) $(FLAGS) -o $(NAME_BONUS) $(SRC_BONUS) $(MLX_FLAGS) libft/*.o ft_printf/*.o
	@echo "Compiled $(NAME_BONUS)"

libft:
	@make -C libft/

printf:
	@make -C ft_printf/

clean:
	@make -C libft/ clean
	@make -C ft_printf/ clean

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@make -C libft/ fclean
	@make -C ft_printf/ fclean

re: fclean all

.PHONY: all bonus libft printf clean fclean re