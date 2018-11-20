NAME = mmc

PATH_SRC = ./

PATH_OBJ = ./

CC = g++

HEAD = include/pol.h

SRC =	src/main.cpp \
		src/functions.cpp \
		src/LaGreanje.cpp

OBJ = $(patsubst %.cpp,%.o,$(addprefix $(PATH_SRC), $(SRC)))

all : $(NAME)

$(NAME): $(OBJ) $(HEAD)
		$(CC) -o $(NAME) $(OBJ)

.PHONY: clean fclean

clean:
		/bin/rm -f $(OBJ)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all