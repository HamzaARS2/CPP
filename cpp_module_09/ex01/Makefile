CC := c++

CFLAGS := -Wall -Wextra -Werror -std=c++98

SOURCES := main.cpp RPN.cpp RPNValidator.cpp
OBJECTS = $(SOURCES:.cpp=.o)
NAME := RPN


all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp RPN.hpp RPNValidator.hpp
	$(CC) $(CFLAGS) -c $< -o $@  

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
