CC := c++

CFLAGS := -Wall -Wextra -Werror 

SOURCES := main.cpp InputFile.cpp OutputFile.cpp IOFileManager.cpp
OBJECTS = $(SOURCES:.cpp=.o)
NAME := fileStreams


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
