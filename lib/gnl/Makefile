CFLAGS+=-Wall -Wextra -Werror -c
NAME=libgnl.a

FILES=\
	get_next_line_bonus.o\
	get_next_line_utils_bonus.o\

.PHONY: all clean fclean re debug

all: $(NAME)

debug: CFLAGS+=-g
debug: all

$(NAME): $(FILES)
	ar rcs $(NAME) $(FILES)

%.o:%.c
	cc $(CFLAGS) -o $@ $<

clean:
	rm -f $(FILES) $(BONUS) *.d
	rm -f $(NAME)

re: fclean all

bonus:	$(FILES) $(BONUS)
	ar rcs $(NAME) $(FILES) $(BONUS)
