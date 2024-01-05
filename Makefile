NAME		=	so_long

SRC			=	src/parsing/path_finding.c		\
				src/parsing/scan_map.c			\
				src/parsing/map.c				\
				src/block.c						\
				src/event.c						\
				src/map_config.c				\
				src/put_img.c					\
				src/window.c					\
				src/coords.c					\
				src/main.c

OBJ			=	$(SRC:.c=.o)

LIBFT		=	libft.a

MLXPATH		= 	/home/aautin/Downloads/mlx

MLXFLG		=	-lXext -lX11

CC			=	cc

CFLG		=	-Wall -Werror -Wextra -g3

RM			=	rm -f

SCR_LEN		=	$(shell xdpyinfo | grep 'dimensions:' | awk '{print $$2}' | awk -Fx '{print $$1}')

SCR_WIDTH	=	$(shell xdpyinfo | grep 'dimensions:' | awk '{print $$2}' | awk -Fx '{print $$2}')

$(NAME)		:	$(OBJ)
				make lib
				$(CC) $(OBJ) -o $(NAME) $(LIBFT) $(MLXPATH)/libmlx.a \
				$(MLXPATH)/libmlx_Linux.a $(MLXFLG)

%.o			:	%.c
				$(CC) $(CFLG) -c $^ -o $@ -D WDW_LEN=$(SCR_LEN) -D WDW_WIDTH=$(SCR_WIDTH)

.PHONY		:	all clean fclean re bonus \
				lib libclean libfclean libre allfcl mlx

all			:	$(NAME)

clean		:
				make clean -C libft
				$(RM) $(OBJ)
				$(RM) $(LIBFT)

fclean		:	clean
				make fclean -C libft
				$(RM) $(NAME)

re			:	fclean all

bonus		:	all

lib			:
				make -C libft
				mv libft/$(LIBFT) $(LIBFT)

libre		:
				make re -C libft

allfcl		:	libfclean fclean

mlx			:
				make -C $(MLXPATH)