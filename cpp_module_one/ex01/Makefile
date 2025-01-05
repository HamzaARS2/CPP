CC := g++

CFLAGS := -Wall -Wextra -Werror -std=c++98

SOURCES := phone.cpp Contact.cpp PhoneBook.cpp utils.cpp
OBJECTS = $(SOURCES:.cpp=.o)
NAME := phone 


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
