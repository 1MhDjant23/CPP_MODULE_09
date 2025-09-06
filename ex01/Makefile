NAME = RPN

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = $(shell find . -name "*.cpp")

HEADERS = $(shell find . -name "*.hpp")

OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re