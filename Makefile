define NEWLINE


endef

CFLAGS+=-Wall -Wextra -Werror -c -MMD -MP
#CFLAGS+=-MMD -MP
export CFLAGS

NAME:=cub3d

FILES:=\
	entity/e_id_from_char\
	entity/entity_create\
	entity/entity_destroy\
	entity/entity_draw\
	entity/entity_get_copy\
	game_logic/patrol_move\
	game_logic/player_move\
	game_logic/run_turn\
	gamestate/gamestate_destroy\
	gamestate/gamestate_init_entities\
	gamestate/gamestate_init_terrain\
	gamestate/gamestate_init\
	gamestate/gamestate_render\
	map/slmap_delete\
	map/slmap_load\
	mlxw/mlxw_colour\
	mlxw/mlxw_draw\
	mlxw/mlxw_destroy_image\
	mlxw/mlxw_draw_string\
	mlxw/mlxw_image_overlay\
	mlxw/mlxw_load_png\
	mlxw/mlxw_load_xpm\
	mlxw/mlxw_new_image\
	sprite/sprite_delete\
	sprite/sprite_load\
	sprite/sprite_draw\
	sprite/sprite_name_from_e_id\
	utils/pos_add\
	utils/pos_equal\
	utils/pos_new\
	utils/pos_rotate\
	close\
	main\

BONUS:=\
	entity/e_id_from_char\
	game_logic/patrol_move\
	sprite/sprite_draw\

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

.PHONY: all clean fclean re bonus debug

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
