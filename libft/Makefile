NAME := libft.a
CC := gcc
CFLAGS := -Wall -Wextra -Werror -std=c99
SRC_FILES := ft_isdigit.c ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c \
			ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
			ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
			ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
			ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRC_FILES_BONUS := ft_lstnew.c ft_lstadd_front.c ft_lstlast.c ft_lstadd_back.c \
					ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
					ft_lstsize.c
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ_FILES_BONUS = $(SRC_FILES_BONUS:.c=.o)

all: obj $(NAME)

bonus: obj_bonus $(OBJ_FILES_BONUS) $(NAME)
	ar rc $(NAME) $(OBJ_FILES_BONUS)
	ranlib $(NAME)

obj: $(SRC_FILES)

obj_bonus: $(SRC_FILES_BONUS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES)
	ar rc $(NAME) $(OBJ_FILES)
	ranlib $(NAME)

clean:
	rm -f $(OBJ_FILES)
	rm -f $(OBJ_FILES_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test:
	gcc -c main.c
	gcc main.o -L. -lft

.PHONY: all clean fclean re libft.a