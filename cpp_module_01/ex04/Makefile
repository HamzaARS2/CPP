CC := g++

CFLAGS := -Wall -Wextra -Werror 

SOURCES := main.cpp InputFile.cpp OutputFile.cpp IOFileManager.cpp
OBJECTS = $(SOURCES:.cpp=.o)
NAME := fileStreams

ADS = -fsanitize=address -g

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(ADS) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(ADS) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
