NAME = push_swap
CC = gcc
CFLAGS = 
SRC  =  	main.c 		ft_simple.c 	ft_radix.c\
			ft_lst.c 	ft_help.c		ft_checker.c

OBJ = $(patsubst %.c,%.o,$(SRC))
INCLUDES = push_swap.h
DIR_LIB = libft
LIB = $(DIR_LIB)/libft.a

all : $(NAME)

lib : 
	make -sC $(DIR_LIB)

$(NAME) : lib $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME) 

%.o : %.c $(INCLUDES)
	gcc $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)
	make clean -C $(DIR_LIB)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(DIR_LIB)
	
re : fclean all

.PHONY : all clean fclean re