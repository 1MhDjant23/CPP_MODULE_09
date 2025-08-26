NAME = PmergeMe

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = $(shell find . -name "*.cpp")

OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp RPN.php
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ) $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re