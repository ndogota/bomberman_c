CC 			=	gcc
CFLAGS 		=	-Wall -Wextra -Werror
LFLAGS		=	-lSDL2 -lSDL2main -lSDL2_image -lSDL2_ttf
NAME		=	bomberman
HEADER		=	include/
SRC_DIR 	=	src
SRC 		= 	$(SRC_DIR)/main.c    \
				$(SRC_DIR)/map.c

OBJ 		=	$(SRC_DIR)/main.o    \
				$(SRC_DIR)/map.o

RM        	=	rm -f

GREEN_COLOR	=	\033[0;92m
RED_COLOR	=	\033[0;91m
OFF_COLOR	=	\033[0m

$(NAME):	$(OBJ)
			@echo "${GREEN_COLOR}Compiling executable :${OFF_COLOR}"
			$(CC) $(CFLAGS) $(LFLAGS) -o $(NAME) $(OBJ) -I $(HEADER)

all: 		$(NAME)


clean:
			@echo "${RED_COLOR}Remove objects files :${OFF_COLOR}"
			$(RM) $(OBJ)

fclean: 	clean
			@echo "${RED_COLOR}Remove outputs files :${OFF_COLOR}"
			$(RM) $(NAME)

re: 		fclean all

.PHONY:    	all clean fclean re
