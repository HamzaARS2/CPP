CC := c++

CFLAGS := -Wall -Wextra -Werror -std=c++98

SOURCES := main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp
OBJECTS = $(SOURCES:.cpp=.o)
NAME := abstract


all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
