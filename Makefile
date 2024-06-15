NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
VPATH = src/
SRCS = fdf.c
OBJS = $(SRCS:.c=.o)
OBJDIR = objs/
OBJS_PATH = $(addprefix $(OBJDIR), $(OBJS))
LIBFT = lib/ft_libft/
PRINTF = lib/ft_printf/
MLX = lib/mlx
INMLX = -L $(MLX)/build -lmlx42 -ldl -L /opt/homebrew/Cellar/glfw/3.3.8/lib/ -lglfw -pthread -lm

$(NAME):		$(OBJS_PATH)
				@cd $(LIBFT) && $(MAKE) all
				@cd $(LIBFT) && $(MAKE) bonus
				@cd $(PRINTF) && $(MAKE) all
				@cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build -j4
				@cc $(OBJS_PATH) $(INLIBFT) $(INPRINF) $(INMLX) -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)

all:			$(NAME)

$(OBJDIR)%.o: %.c
				@mkdir -p $(dir $@)
				@cc -c $< -o $@ $(CFLAGS)

clean:
				@rm -rf $(OBJDIR)
				@cd $(LIBFT) && $(MAKE) clean
				@cd $(PRINTF) && $(MAKE) clean
				@rm -rf $(MLX)/build

fclean:			clean
				@rm -f $(NAME)
				@cd $(LIBFT) && $(MAKE) fclean
				@cd $(PRINTF) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re