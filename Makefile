NAME			:=	so_long

INC_PATH		:=	inc

LIB_PATH		:=	libft
LIB_FILE		:=	libft.a
LIB				:=	$(addprefix $(LIB_PATH)/,$(LIB_FILE))
INC_LIB			:=	-L $(LIB_PATH) -l ft

MLX_TGZ			:=	mlx.tgz 
MLX				:=	mlx
MLX_LIB			:=	$(MLX)/libmlx_Linux.a

SRC_PATH		:=	src
SRC_FILES		:=	main.c			\
					parsing.c		\
					coords.c		\
					utils.c			\
					path_finding.c
SRC				:=	$(addprefix $(SRC_PATH)/,$(SRC_FILES))

OBJ_PATH		:=	obj
OBJ_FILES		:=	$(SRC_FILES:.c=.o)
OBJ				:=	$(addprefix $(OBJ_PATH)/,$(OBJ_FILES))

RM				:=	rm -f
CC_FLGS			:=	cc -Wall -Werror -Wextra -g3

LEN		:= $(shell xdpyinfo | grep dim | awk '{print $$2}' | awk -Fx '{print $$1}')
WID		:= $(shell xdpyinfo | grep dim | awk '{print $$2}' | awk -Fx '{print $$2}')
IMGS	:= $(shell readlink -f sprites/* sprites/*/* | grep .xpm)
MACROS	:= -DSCR_LEN=$(LEN) -DSCR_WID=$(WID) -DIMGS=\""$(IMGS)\""

all				:	$(NAME)

.PHONY			:	all clean fclean re

$(NAME)			:	$(LIB) $(MLX) $(MLX_LIB) $(OBJ_PATH) $(OBJ)
					@sleep 0.2
					@echo -n "$(GREEN)"
					@$(CC_FLGS) $(OBJ) -o $(NAME) $(INC_LIB) 
					@echo $@ "has been created !$(NO_COLOR)"

$(MLX_LIB)		:	$(MLX)
					@sleep 0.1
					@echo "$(BLUE)Compiling the mlx...$(NO_COLOR)"
					@make --no-print-directory --silent -C mlx

$(MLX)			:	$(MLX_TGZ)
					@sleep 0.1
					@echo "$(YELLOW)Extracting the mlx, creating the mlx...$(NO_COLOR)"
					@tar -x -f $(MLX_TGZ) && mv minilibx-linux $(MLX)

$(OBJ_PATH)/%.o	:	$(SRC_PATH)/%.c
					@sleep 0.1
					@echo "$(BLUE)Compiling $@$(NO_COLOR)"
					@$(CC_FLGS) -c $< -o $@ -I $(INC_PATH) $(MACROS)

$(OBJ_PATH)		:
					@mkdir $@

$(LIB)			:
					@sleep 0.1
					@make --no-print-directory -C libft
					@echo "$(YELLOW)Compiling the libft...$(NO_COLOR)"

clean			:
					@sleep 0.1
					@$(RM) $(OBJ)
					@echo "$(RED)Deleting objects files...$(NO_COLOR)"
					@sleep 0.2
					@echo "$(RED)Cleaning the libft folder...$(NO_COLOR)"
					@make clean --no-print-directory -C libft

fclean			:	clean
					@sleep 0.1
					@$(RM) $(NAME) $(LIB)
					@echo "$(RED)Deleting so_long and the libft.a...$(NO_COLOR)"
					@sleep 0.2
					@$(RM) -r $(MLX)
					@echo "$(RED)Deleting the mlx folder...$(NO_COLOR)"
					@sleep 0.3

re				:	fclean all

NO_COLOR		:=	\033[0m
BLACK			:=	\033[0;30m
BLUE			:=	\033[0;34m
GREEN			:=	\033[0;32m
CYAN			:=	\033[0;36m	
RED				:=	\033[0;31m
PURPLE			:=	\033[0;35m
YELLOW			:=	\033[0;33m
GRAY			:=	\033[0;37m