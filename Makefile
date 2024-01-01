NAME		=	so_long

SRC			=	src/parsing/path_finding.c		\
				src/parsing/map.c				\
				src/coords.c					\
				src/main.c

OBJ			=	$(SRC:.c=.o)

LIBFT		=	libft.a

MLXPATH		= 	/home/aautin/Downloads/mlx

MLXFLG		=	-lXext -lX11

CC			=	cc

CFLG		=	-Wall -Werror -Wextra

RM			=	rm -f

$(NAME)		:	$(OBJ)
				make lib
				$(CC) $(OBJ) -o $(NAME) $(LIBFT) $(MLXPATH)/libmlx.a \
				$(MLXPATH)/libmlx_Linux.a $(MLXFLG)

%.o			:	%.c
				$(CC) $(CFLG) -c $^ -o $@

.PHONY		:	all clean fclean re bonus \
				lib libclean libfclean libre allfcl mlx

all			:	$(NAME)

clean		:
				$(RM) $(OBJ)
				$(RM) $(LIBFT)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

bonus		:	all

lib			:
				make -C libft
				mv libft/$(LIBFT) $(LIBFT)

libclean	:
				make clean -C libft

libfclean	:
				make fclean -C libft

libre		:
				make re -C libft

allfcl		:	libfclean fclean

mlx			:
				make -C $(MLXPATH)