NAME= cub3D

NAME_BONUS = cub3D_bonus

MAIN= src/main.c

PARSER= parser.c parser_header.c parser_map.c parser_save.c parser_init.c parser_sprite.c

UTILS= utils_parse.c utils_lst.c utils_save_map.c utils_parse2.c free.c

SPRITE= sprite_utils.c animation.c sprite_raycast.c

INIT= mlx.c player.c

EVENT= handler.c moves_1.c moves_2.c mouse.c

MINIMAP= minimap_1.c minimap_2.c minimap_3.c

RENDER= utils.c raycast.c  floor_cast.c render.c wall_raycast.c

DRAW= draw.c color_1.c color_2.c bresenham.c

TEXTURES= textures.c

DOOR= door_raycast.c door_utils_1.c door_utils_2.c

OBJS_PARSER = $(addprefix src/parser/, $(PARSER:.c=.o))

OBJS_UTILS = $(addprefix src/utils/, $(UTILS:.c=.o))

OBJS_INIT = $(addprefix src/init/, $(INIT:.c=.o))

OBJS_EVENT = $(addprefix src/event/, $(EVENT:.c=.o))

OBJS_RENDER = $(addprefix src/render/, $(RENDER:.c=.o))

OBJS_DRAW = $(addprefix src/draw/, $(DRAW:.c=.o))

OBJS_TEXTURES = $(addprefix src/textures/, $(TEXTURES:.c=.o))

OBJS_SPRITE = $(addprefix src/sprite/, $(SPRITE:.c=.o))

OBJS_DOOR = $(addprefix src/door/, $(DOOR:.c=.o))

OBJS_MINIMAP = $(addprefix src/minimap/, $(MINIMAP:.c=.o))

OBJS= $(OBJS_PARSER) $(MAIN:.c=.o) $(OBJS_UTILS) $(OBJS_INIT) $(OBJS_EVENT) $(OBJS_RENDER) $(OBJS_DRAW) $(OBJS_TEXTURES) $(OBJS_SPRITE) $(OBJS_DOOR) $(OBJS_MINIMAP)

CFLAGS= -Wall -Werror -Wextra -g3

CC=cc

MLXLIB = mlx_linux/libmlx_Linux.a

all: $(NAME)

$(MLXLIB):
	make -C mlx_linux

$(NAME): $(OBJS) $(MLXLIB)
	make -C libft
	 $(CC) $(OBJS) $(MLXLIB) -Lmlx_linux -lmlx_Linux -L/usr/lib -lft -L./libft -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I./include -I/usr/include -Imlx_linux -O3 -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS) $(MLXLIB)
	make -C libft
	 $(CC) $(OBJS) $(MLXLIB) -Lmlx_linux -lmlx_Linux -L/usr/lib -lft -L./libft -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	make clean -C libft
	make -C mlx_linux clean
	rm -f $(OBJS)

fclean:
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
