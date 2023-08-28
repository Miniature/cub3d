CFLAGS?=-Wall -Wextra -Werror -c -I. -Iinclude
export CFLAGS
NAME:=so_long
FILES:=\
	main\

SRC_DIR:=src
OBJ_DIR:=obj
OBJ_FILES:=$(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(FILES)))

LIBS:=\
	libftprintf\
	get_next_line\

MLX:=lib/libmlx

LIBS:=$(addsuffix .a, $(addprefix lib/, $(join $(LIBS), $(addprefix /, $(LIBS)))))

.PHONY: all clean fclean re bonus debug

all: debug

debug: CFLAGS+=-g
debug: $(NAME)

$(NAME):$(LIBS) $(OBJ_FILES) libmlx.dylib
	cc -o $(NAME) $(OBJ_FILES) $(LIBS) libmlx.dylib

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	cc $(CFLAGS) -o $@ $<

$(LIBS):
	$(MAKE) -C $(dir $@)

libmlx.dylib:
	$(MAKE) -C $(MLX)
	cp -R $(MLX)/libmlx.dylib* .

clean:
	rm -rf obj
	$(foreach lib, $(LIBS), $(shell $(MAKE) -C $(dir $(lib)) clean))
	$(MAKE) -C $(MLX) clean

fclean: clean
	rm -f $(NAME)
	rm -rf libmlx.dylib*

re: fclean all

#bonus: all
