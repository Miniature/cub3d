define NEWLINE


endef

CFLAGS+=-Wall -Wextra -Werror -c -MMD -MP
#CFLAGS+=-MMD -MP
export CFLAGS

NAME:=cub3D

DEBUG_ARGS:=\
	rsc/map/ex1.cub\

FILES:=\
	entity/e_id_from_char\
	entity/entity_create\
	entity/entity_destroy\
	entity/entity_draw\
	entity/entity_get_copy\
	game_logic/on_key\
	game_logic/patrol_move\
	game_logic/player_move\
	game_logic/run_turn\
	gamestate/gamestate_destroy\
	gamestate/gamestate_init_entities\
	gamestate/gamestate_init_terrain\
	gamestate/gamestate_init_background\
	gamestate/gamestate_init_config\
	gamestate/gamestate_init\
	gamestate/gamestate_render_minimap\
	gamestate/gamestate_render\
	gamestate/map_enclosed\
	map/slmap_delete\
	map/slmap_load\
	map/slmap_get_block\
	mlxw/mlxw_colour\
	mlxw/mlxw_draw\
	mlxw/mlxw_destroy_image\
	mlxw/mlxw_draw_string\
	mlxw/mlxw_image_overlay\
	mlxw/mlxw_load_png\
	mlxw/mlxw_load_xpm\
	mlxw/mlxw_new_image\
	mlxw/mlxw_subimage\
	sprite/sprite_delete\
	sprite/sprite_load\
	sprite/sprite_draw\
	sprite/sprite_name_from_e_id\
	utils/error\
	utils/pos_add\
	utils/pos_equal\
	utils/pos_mult\
	utils/pos_near\
	utils/pos_new\
	utils/pos_rotate\
	render/render_draw\
	render/render\
	raycasting/raycasting\
	raycasting/raycasting_perspective_init\
	close\
	main\

BONUS:=\

SRC_DIR:=src
OBJ_DIR:=obj

OBJ_FILES=$(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(FILES)))
OBJ_FILES_BONUS=$(addsuffix _bonus.o, $(addprefix $(OBJ_DIR)/, $(BONUS))) $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(filter-out $(BONUS), $(FILES))))

INCLUDES:=-Iinclude -I$(SRC_DIR)

SLIBS:=\
	ftprintf\
	gnl\

SLIBPATHS=$(addsuffix .a, $(join $(addprefix lib/, $(SLIBS)), $(addprefix /lib, $(SLIBS))))

DYLIBS:=\
	mlx\

DYLIBPATHS=$(addsuffix .dylib, $(join $(addprefix lib/, $(DYLIBS)), $(addprefix /lib, $(DYLIBS))))

.PHONY: all clean fclean re bonus debug test

bonus: $(SLIBPATHS) $(DYLIBPATHS) $(OBJ_FILES_BONUS)
bonus: OBJ_FILES=$(OBJ_FILES_BONUS)
bonus: all

all: $(NAME)

debug: CFLAGS+=-g -MMD -MP
debug: bonus

-include $(OBJ_FILES:.o=.d)

$(NAME): $(SLIBPATHS) $(DYLIBPATHS) $(OBJ_FILES)
	cc -o $(NAME) $(OBJ_FILES) $(dir $(addprefix -L./, $(SLIBPATHS))) $(addprefix -l, $(SLIBS)) $(dir $(addprefix -L./, $(DYLIBPATHS))) $(addprefix -l, $(DYLIBS))
	$(foreach dylib, $(DYLIBPATHS), cp $(dylib) .)
	$(foreach dylib, $(DYLIBPATHS), install_name_tool -change $(notdir $(dylib)) @executable_path/$(notdir $(dylib)) $(NAME)$(NEWLINE))
#i hate macs

-include $(OBJ_FILES:.o=.d)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	cc $(CFLAGS) -o $@ $< $(INCLUDES)

%.a:
	$(MAKE) -C $(dir $@)

%.dylib:
	$(MAKE) -C $(dir $@)

clean:
	rm -rf obj
	$(foreach lib, $(dir $(SLIBPATHS)),$(MAKE) -C $(lib) clean$(NEWLINE))
	$(foreach dylib, $(DYLIBPATHS), $(MAKE) -C $(dir $(dylib)) clean$(NEWLINE))

fclean: clean
	rm -f $(NAME) $(notdir $(DYLIBPATHS))

re: fclean all

test: debug
	$(foreach arg, $(TEST_ARGS), ./$(NAME) $(ARG))
