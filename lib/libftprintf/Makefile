CFLAGS=-Wall -Wextra -Werror -Iinclude -I. -c
NAME=libftprintf.a
LIBFT_FILES=\
	libft/ft_atoi.o\
	libft/ft_bzero.o\
	libft/ft_calloc.o\
	libft/ft_isalnum.o\
	libft/ft_isalpha.o\
	libft/ft_isascii.o\
	libft/ft_isdigit.o\
	libft/ft_isprint.o\
	libft/ft_itoa.o\
	libft/ft_memchr.o\
	libft/ft_memcmp.o\
	libft/ft_memcpy.o\
	libft/ft_memmove.o\
	libft/ft_memset.o\
	libft/ft_putchar_fd.o\
	libft/ft_putendl_fd.o\
	libft/ft_putnbr_fd.o\
	libft/ft_putstr_fd.o\
	libft/ft_split.o\
	libft/ft_strchr.o\
	libft/ft_strdup.o\
	libft/ft_striteri.o\
	libft/ft_strjoin.o\
	libft/ft_strlcat.o\
	libft/ft_strlcpy.o\
	libft/ft_strlen.o\
	libft/ft_strmapi.o\
	libft/ft_strncmp.o\
	libft/ft_strnstr.o\
	libft/ft_strrchr.o\
	libft/ft_strtrim.o\
	libft/ft_substr.o\
	libft/ft_tolower.o\
	libft/ft_toupper.o\
	libft/ft_lst_delone_bonus.o\
	libft/ft_lstadd_back_bonus.o\
	libft/ft_lstadd_front_bonus.o\
	libft/ft_lstclear_bonus.o\
	libft/ft_lstiter_bonus.o\
	libft/ft_lstlast_bonus.o\
	libft/ft_lstmap_bonus.o\
	libft/ft_lstnew_bonus.o\
	libft/ft_lstsize_bonus.o\

FILES=\
	ft_printf\
	ft_printf_handlers\
	ft_printf_handler_decimal\
	ft_printf_handler_string\
	ft_printf_handler_hex\
	ft_putnstr_fd\
	ft_putnchars_fd\
	ft_math_min\
	ft_math_max\
	ft_utoa_base\
	ft_strjoin_free\

SRC_DIR=src
OBJ_DIR=obj
OBJ_FILES=$(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(FILES)))

.PHONY: all clean fclean re bonus t tclean debug tt

all: $(NAME)

debug: CFLAGS+=-g
debug: all

$(NAME):$(LIBFT_FILES) $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES) $(LIBFT_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	cc $(CFLAGS) -o $@ $<

clean:
	rm -rf obj
	rm -f $(LIBFT_FILES)
	rm -f $(NAME)

re: clean all

bonus: all
