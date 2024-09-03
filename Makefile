NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
VPATH = src/
SRCS = fdf.c \
		draw_line.c \
		parsing.c \
		parsing2.c \
		rotate.c \
		line_algo.c \
		key_actions.c \
		test.c \
		menu.c \
		drawMap.c \
		rotateOrtho.c
OBJS = $(SRCS:.c=.o)
OBJDIR = objs/
OBJS_PATH = $(addprefix $(OBJDIR), $(OBJS))
LIBFT = lib/ft_libft/
PRINTF = lib/ft_printf/
GET_NEXT = lib/ft_get_next_line/
MLX = lib/mlx
INLIBFT = -L $(LIBFT) -lft
INPRINF = -L $(PRINTF) -lftprintf
INGETNEXT = -L $(GET_NEXT) -l_get_next_line
INMLX = -L $(MLX)/build -lmlx42 -ldl -L /opt/homebrew/Cellar/glfw/3.3.8/lib/ -lglfw -pthread -lm
# /usr/local/lib/


all:			$(NAME)

submodules:
				git submodule update --init --recursive

$(NAME):		submodules $(OBJS_PATH)
				@cd $(LIBFT) && $(MAKE) all
				@cd $(LIBFT) && $(MAKE) bonus
				@cd $(PRINTF) && $(MAKE) all
				@cd $(GET_NEXT) && $(MAKE) all
				@cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build -j4
				@cc $(OBJS_PATH) $(INLIBFT) $(INPRINF) $(INGETNEXT) $(INMLX) -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)

$(OBJDIR)%.o: %.c
				@mkdir -p $(dir $@)
				@cc -c $< -o $@ $(CFLAGS)

clean:
				@rm -rf $(OBJDIR)
				@cd $(LIBFT) && $(MAKE) clean
				@cd $(PRINTF) && $(MAKE) clean
				@cd $(GET_NEXT) && $(MAKE) clean
				@rm -rf $(MLX)/build

fclean:			clean
				@rm -f $(NAME)
				@cd $(LIBFT) && $(MAKE) fclean
				@cd $(PRINTF) && $(MAKE) fclean
				@cd $(GET_NEXT) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re