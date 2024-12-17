SRCS = ./parsing/parsing.c \
		./parsing/path.c \
		./parsing/so_long_utils.c \
		./moov/set_sprites.c \
		./moov/moov.c \
		./moov/sprites_moov.c \
		./moov/hook.c \
		./moov/main.c 

SRCS_BONUS = ./parsing_bonus/parsing_bonus.c \
		./parsing_bonus/path_bonus.c \
		./parsing_bonus/so_long_utils_bonus.c \
		./moov_bonus/set_sprites_bonus.c \
		./moov_bonus/moov_bonus.c \
		./moov_bonus/sprites_moov_bonus.c \
		./moov_bonus/hook_bonus.c \
		./moov_bonus/enemy.c \
		./moov_bonus/element.c \
		./moov_bonus/game.c \
		./moov_bonus/startgame.c \
		./moov_bonus/moves.c \
		./moov_bonus/moves_two.c \
		./moov_bonus/main_bonus.c 

OBJS_MAIN = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

ifndef BONUS
OBJS = $(OBJS_MAIN)
else
OBJS = $(OBJS_BONUS)
endif

RED = \033[31;2m
BLACK = \033[38;5;238m
BLUE = \033[38;5;153m
GREEN = \033[38;5;48m
BOLD = \033[1m
UNDERLINE = \033[4m
YELLOW = \033[38;5;226m
ORANGE = \033[38;5;202m
PINK = \033[38;5;198m
PURPLE = \033[38;5;147m

CC = gcc
CFLAGS = -Wall -Werror -Wextra -Imlx
ifdef DEBUG
CFLAGS += -fsanitize=address -g3
endif

OS := $(shell uname)

ifeq ($(OS), Darwin)
	MLX_DIR = minilibx-opengl
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
	MLX_DIR = minilibx-linux
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
endif

.c.o:
	@$(CC) $(CFLAGS) -c -I ./inc/ $< -o $(<:.c=.o)

NAME = so_long
all : $(NAME)

$(NAME): $(OBJS_MAIN) $(OBJS_BONUS)
	@echo "	$(PURPLE)$(UNDERLINE)Compiling...\033[0m"
	@$(MAKE) -C ./libft/
	@$(MAKE) -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) ./libft/libft.a -o $(NAME)
	# @clear
	@echo "	$(PINK)$(BOLD)Compiled ! \033[0m"

debug:
	@$(MAKE) DEBUG=1

bonus: 
	@$(MAKE) BONUS=1

clean:
	@$(MAKE) clean -C ./libft/
	@$(MAKE) clean -C $(MLX_DIR)
	@rm -rf $(OBJS_MAIN) $(OBJS_BONUS)
	@echo "	$(RED)Deleted file .o \033[0m"

fclean: clean
	@rm -rf ./libft/libft.a
	@rm -rf $(NAME)
	@echo "	$(RED)Deleted file .a\033[0m"

re: fclean all

.PHONY: all clean fclean re debug
