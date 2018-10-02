NAME = mmc

PATH_SRC = ./

PATH_OBJ = ./

CC = g++

HEAD = include/mmc.h

SRC =	src/main.cpp \
		src/ft_jumint.cpp \
		src/ft_aprsuc.cpp \
		src/ft_newton.cpp \
		src/ft_secant.cpp

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