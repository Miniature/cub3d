#CFLAGS?=-Wall -Wextra -Werror -c
CFLAGS+=-Wall -Wextra -Werror -c
NAME=libft.a

FILES=\
	ft_atoi.o\
	ft_bzero.o\
	ft_calloc.o\
	ft_isalnum.o\
	ft_isalpha.o\
	ft_isascii.o\
	ft_isdigit.o\
	ft_isprint.o\
	ft_itoa.o\
	ft_memchr.o\
	ft_memcmp.o\
	ft_memcpy.o\
	ft_memmove.o\
	ft_memset.o\
	ft_putchar_fd.o\
	ft_putendl_fd.o\
	ft_putnbr_fd.o\
	ft_putstr_fd.o\
	ft_split.o\
	ft_strchr.o\
	ft_strdup.o\
	ft_striteri.o\
	ft_strjoin.o\
	ft_strlcat.o\
	ft_strlcpy.o\
	ft_strlen.o\
	ft_strmapi.o\
	ft_strncmp.o\
	ft_strnstr.o\
	ft_strrchr.o\
	ft_strtrim.o\
	ft_substr.o\
	ft_tolower.o\
	ft_toupper.o\

BONUS=\
	ft_lst_delone_bonus.o\
	ft_lstadd_back_bonus.o\
	ft_lstadd_front_bonus.o\
	ft_lstclear_bonus.o\
	ft_lstiter_bonus.o\
	ft_lstlast_bonus.o\
	ft_lstmap_bonus.o\
	ft_lstnew_bonus.o\
	ft_lstsize_bonus.o\

.PHONY: all clean fclean re bonus debug

all: $(NAME)

debug: CFLAGS+=-g
debug: all

$(NAME): $(FILES)
	ar rcs $(NAME) $(FILES)

%.o:%.c
	cc $(CFLAGS) -o $@ $<

clean:
	rm -f $(FILES) $(BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus:	$(FILES) $(BONUS)
	ar rcs $(NAME) $(FILES) $(BONUS) *.d
