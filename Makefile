CFLAGS?=-Wall -Wextra -Werror -c -I. -Iinclude -I$(SRC_DIR)
export CFLAGS
NAME:=so_long
FILES:=\
	entity/entity_create\
	entity/entity_destroy\
	entity/entity_draw\
	gamestate/gamestate_init_entities\
	gamestate/gamestate_init_terrain\
	gamestate/gamestate_init\
	gamestate/gamestate_render\
	map/slmap_delete\
	map/slmap_load\
	mlxw/mlxw_colour\
	mlxw/mlxw_draw\
	mlxw/mlxw_destroy_image\
	mlxw/mlxw_image_overlay\
	mlxw/mlxw_load_png\
	mlxw/mlxw_load_xpm\
	mlxw/mlxw_new_image\
	sprite/sprite_delete\
	sprite/sprite_load\
	sprite/sprite_draw\
	utils/pos_equal\
	utils/pos_new\
	main\

SRC_DIR:=src
OBJ_DIR:=obj
OBJ_FILES:=$(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(FILES)))

SLIBS:=\
	libftprintf\
	get_next_line\

MLX:=lib/libmlx

SLIBS:=$(addsuffix .a, $(addprefix lib/, $(join $(SLIBS), $(addprefix /, $(SLIBS)))))

.PHONY: all clean fclean re bonus debug

all: debug

debug: CFLAGS+=-g
debug: $(NAME)

$(NAME):$(SLIBS) $(OBJ_FILES) libmlx.dylib
	cc -o $(NAME) $(OBJ_FILES) $(SLIBS) libmlx.dylib
	install_name_tool -change libmlx.dylib @executable_path/libmlx.dylib $(NAME)
#i hate macs

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	cc $(CFLAGS) -o $@ $<

$(SLIBS):
	$(MAKE) -C $(dir $@)

libmlx.dylib:
	$(MAKE) -C $(MLX)
	cp -R $(MLX)/libmlx.dylib* .

clean:
	rm -rf obj
	$(foreach lib, $(SLIBS), $(shell $(MAKE) -C $(dir $(lib)) clean))
	$(MAKE) -C $(MLX) clean

fclean: clean
	rm -f $(NAME)
	rm -rf libmlx.dylib*

re: fclean all

#bonus: all
