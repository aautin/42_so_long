NAME		=	so_long

SRC			=	src/main.c

OBJ			=	$(SRC:.c=.o)

LIB			=	libft.a

CC			=	cc

CFLG		=	-Wall -Werror -Wextra

RM			=	rm -f

$(NAME)		:	$(OBJ)
				make lib
				$(CC) $(OBJ) -o $(NAME) $(LIB)

%.o			:	%.c
				$(CC) $(CFLG) -c $^ -o $@

.PHONY		:	all clean fclean re bonus lib libclean libfclean libre allfcl

all			:	$(NAME)

clean		:
				$(RM) $(OBJ)
				$(RM) $(LIB)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

bonus		:	all

lib			:
				make -C libft
				mv libft/$(LIB) $(LIB)

libclean	:
				make clean -C libft

libfclean	:
				make fclean -C libft

libre		:
				make re -C libft

allfcl		:	libfclean fclean
