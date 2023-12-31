NAME		:=	so_long

INC_PATH	:=	includes

LIB_PATH	:=	libft
LIB_FILE	:=	libft.a
LIB			:=	$(addprefix $(LIB_PATH)/,$(LIB_FILE))

SRC_PATH	:=	src
SRC_FILES	:=	main.c
SRC			:=	$(addprefix $(SRC_PATH)/,$(SRC_FILES))

OBJ_PATH	:=	obj
OBJ_FILES	:=	$(SRC_FILES:.c=.o)
OBJ			:=	$(addprefix $(OBJ_PATH)/,$(OBJ_FILES))

RM			:=	rm -f
CC_FLGS		:=	cc -Wall -Werror -Wextra -g3

.PHONY		:	all clean fclean re



$(OBJ_PATH)	:
				@echo $(RED) MSG="uwyer"

$(NAME)		:	$(LIB) $(OBJ)
				$(CC_FLGS) -c $(NAME) -o $(OBJ)

clean		:
				@sleep 0.1
				@echo -n $(RED)
				@$(RM) $(OBJ)
				@echo "Deleting objects files..." $(NO_COLOR)

fclean		:	clean
				@sleep 0.1
				@echo -n $(RED)
				@$(RM) $(NAME) $(LIB)
				@echo "Deleting so_long and the libft.a..." $(NO_COLOR)

NO_COLOR		:=	"\033[0m"
BLACK			:=	"\033[0;30m"
BLUE			:=	"\033[0;34m"
GREEN			:=	"\033[0;32m"
CYAN			:=	"\033[0;36m"
RED				:=	"\033[0;31m"
PURPLE			:=	"\033[0;35m"
YELLOW			:=	"\033[0;33m"
GRAY			:=	"\033[0;37m"