CC := g++

CFLAGS := -Wall -Wextra -Werror -std=c++98

SOURCES := megaphone.cpp
OBJECTS = $(SOURCES:.cpp=.o)
NAME := megaphone 


all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

megaphone.o: megaphone.cpp
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
