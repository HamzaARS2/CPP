CC := c++

CFLAGS := -Wall -Wextra -Werror -std=c++98

SOURCES := main.cpp Student.cpp
OBJECTS = $(SOURCES:.cpp=.o)
NAME := array

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
