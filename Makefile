NAME = fractol

CC = gcc

CFLAG = -Wall -Wextra -Werror

SRC = ./src/main.c ./src/tools.c ./src/fractal.c ./src/deco.c ./src/init_fract.c ./src/initri.c


OBJECTS = $(SRC:.c=.o)
	RED=\033[1;31m
	GREEN=\033[1;32m

all : $(NAME)

$(NAME): $(OBJECTS)
	@$(MAKE) -C libft
	@$(MAKE) -C minilibx_macos
	@$(CC) $(CFLAG) -o $(NAME) $(OBJECTS) -L./libft -lft -g -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit
	@echo "$(GREEN)[✓]Ready!"

clean :
	@make -C minilibx_macos clean
	@make -C libft clean
	@rm -rf $(OBJECTS) libft.a libmlx.a
	@echo "$(RED)[✓]Clean!"

fclean : clean
	@rm -f $(NAME)
	@make -C libft fclean
	@echo "$(RED)[✓]All clean!"

re : fclean all

.PHONY : clean fclean all

