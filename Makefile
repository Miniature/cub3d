CFLAGS:=-Wall -Wextra -Werror -c -I. -Iinclude
export CFLAGS
NAME:=so_long
FILES:=\

SRC_DIR:=src
OBJ_DIR:=obj
OBJ_FILES:=$(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(FILES)))

LIBS:=\
	libftprintf\
	libmlx\

LIBS:=$(addsuffix .a, $(addprefix lib/, $(join $(LIBS), $(addprefix /, $(LIBS)))))

.PHONY: all clean fclean re bonus debug

all: $(NAME)

debug: CFLAGS+=-g
debug: all

$(NAME):$(LIBS) $(OBJ_FILES)
	cc -o $(NAME) $(OBJ_FILES) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	cc $(CFLAGS) -o $@ $<

$(LIBS):
	$(MAKE) -C $(dir $@)

clean:
	rm -rf obj
	$(foreach lib, $(LIBS), $(shell $(MAKE) -C $(dir $(lib)) clean))

fclean: clean
	rm -f $(NAME)

re: fclean all

#bonus: all
