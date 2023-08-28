CFLAGS?=-Wall -Wextra -Werror -Iinclude -I. -c
NAME:=get_next_line.a

FILES:=\
	get_next_line_bonus\
	get_next_line_utils_bonus\

OBJ:=$(addsuffix .o, $(FILES))

.PHONY: all clean fclean re bonus

all: $(NAME)

debug: CFLAGS+=-g
debug: all

$(NAME):$(LIBFT_FILES) $(OBJ)
	ar rcs $(NAME) $(OBJ) $(LIBFT_FILES)

%.o: %.c
	cc $(CFLAGS) -o $@ $<

clean:
	rm -f *.o
	rm -f $(NAME)

re: clean all
