CC := g++

CFLAGS := -Wall -Wextra -Werror -std=c++98

SOURCES := main.cpp newZombie.cpp randomChump.cpp Zombie.cpp

OBJECTS := $(SOURCES:.cpp=.o)

NAME := zombie

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