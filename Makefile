NAME = fdf
CFLAGS = -Wall -Werror -Wextra
SRC = src/fdf.c \
		src/drawing/draw_line.c \
		src/parsing/parsing.c \
		src/parsing/parsing_utils.c \
		src/parsing/parsing_utils_2.c \
		src/drawing/rotate.c \
		src/drawing/line_algo.c \
		src/utils/key_actions.c \
		src/utils/key_actions_utils.c \
		src/utils/menu.c \
		src/utils/menu_utils.c \
		src/drawing/draw_map.c \
		src/drawing/rotateOrtho.c \
		src/drawing/rotate_utils.c

OBJDIR = objs/
OBJ = $(SRC:.c=.o)
OBJS_PATH = $(addprefix $(OBJDIR), $(OBJ))
LIBFT = lib/ft_libft/
PRINTF = lib/ft_printf/
GET_NEXT = lib/ft_get_next_line/
MLX = lib/mlx
INLIBFT = -L $(LIBFT) -lft
INPRINF = -L $(PRINTF) -lftprintf
INGETNEXT = -L $(GET_NEXT) -l_get_next_line
INMLX = -L $(MLX)/build -lmlx42 -ldl -L /usr/local/lib/ -lglfw -pthread -lm

# /opt/homebrew/Cellar/glfw/3.3.8/lib/


all:		submodules $(OBJDIR) $(NAME)

$(NAME):	logo $(OBJS_PATH)
				@cd $(LIBFT) && $(MAKE) bonus
				@cd $(PRINTF) && $(MAKE) all
				@cd $(GET_NEXT) && $(MAKE) all
				@cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build -j4
				@cc $(OBJS_PATH) $(INLIBFT) $(INPRINF) $(INGETNEXT) $(INMLX) -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)

$(OBJDIR)%.o: %.c | $(OBJDIR)
			@mkdir -p $(dir $@)
			@cc -c $< -o $@ $(CFLAGS)
			@if [ "$(filter $<,$(SRC))" ]; then $(MAKE) progress; fi

$(OBJDIR):
				@mkdir -p $(OBJDIR)

submodules:
				git submodule update --init --recursive

progress:
				@$(eval PROGRESS := $(shell echo $$(($(shell find $(SRC) -name '*.c' | wc -l) - $$(find $(OBJDIR) -name '*.o' | wc -l)))))
				@$(eval TOTAL := $(shell find $(SRC) -name '*.c' | wc -l))
				@$(eval PERCENT := $(shell echo "scale=2; (1 - $(PROGRESS) / $(TOTAL)) * 100" | bc))
				@$(eval BAR := $(shell printf '=%.0s' {1..$(shell echo "scale=0; $(PERCENT) / 2" | bc)}))
				@printf "\r[%-50s] %s%%" "$(BAR)" "$(PERCENT)"
				@if [ "$(PERCENT)" = "100.00" ]; then printf "\n"; fi
				@if [ "$(PERCENT)" = "100.00" ]; then printf "\033[0;32mfdf compiled\033[0m\n"; fi

clean:
				@rm -rf $(OBJDIR)
				@cd $(LIBFT) && $(MAKE) clean
				@cd $(PRINTF) && $(MAKE) clean
				@cd $(GET_NEXT) && $(MAKE) clean
				@rm -rf $(MLX)/build

fclean:		clean
				@rm -f $(NAME)
				@cd $(LIBFT) && $(MAKE) fclean
				@cd $(PRINTF) && $(MAKE) fclean
				@cd $(GET_NEXT) && $(MAKE) fclean

re:			fclean all

logo:
				@echo "  ▄████████  ████████▄    ▄████████"
				@echo "  ███    ███ ███   ▀███   ███    ███"
				@echo "  ███    █▀  ███    ███   ███    █▀ "
				@echo " ▄███▄▄▄     ███    ███  ▄███▄▄▄    "
				@echo "▀▀███▀▀▀     ███    ███ ▀▀███▀▀▀    "
				@echo "  ███        ███   ▄███   ███       "
				@echo "  ███        ████████▀    ███       "


.PHONY: all clean fclean re bonus progress progressb logo submodules
