CC := c++

CFLAGS := -Wall -Wextra -Werror -std=c++98

SOURCES := main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
NAME := MutantStack


all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp MutantStack.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
