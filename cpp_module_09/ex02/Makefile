CC := c++

CFLAGS := -Wall -Wextra -Werror -std=c++98

SOURCES := main.cpp VectorSort.cpp
OBJECTS = $(SOURCES:.cpp=.o)
NAME := PmergeMe


all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp PmergeMe.hpp
	$(CC) $(CFLAGS) -c $< -o $@  

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
