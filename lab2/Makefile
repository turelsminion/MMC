NAME = mmc

PATH_SRC = ./

PATH_OBJ = ./

CC = g++

HEAD = include/matrix.h

SRC =	src/main.cpp \
		src/cholesky.cpp \
		src/Jacobi.cpp \
		src/Gaus_Seidel.cpp \
		src/elim_Gaus.cpp

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