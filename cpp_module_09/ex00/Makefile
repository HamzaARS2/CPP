CC := c++

CFLAGS := -Wall -Wextra -Werror -std=c++98

SOURCES := main.cpp MapBitcoinDB.cpp BitcoinExchange.cpp
OBJECTS = $(SOURCES:.cpp=.o)
NAME := btc


all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp BitcoinExchange.hpp MapBitcoinDB.hpp
	$(CC) $(CFLAGS) -c $< -o $@  

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
