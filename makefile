NAME = program

CC = gcc
CXX = g++

CFLAGS = -Wall -Wextra -Werror
CXXFLAGS = -Wall -Wextra -Werror

C_FILES = \
	MY_LIBFT_C-main/VECTOR_VOID.c \
	MY_LIBFT_C-main/LIBFT_STRING.c

CPP_FILES = \
	Main.cpp

C_OBJECTS = $(C_FILES:.c=.o)
CPP_OBJECTS = $(CPP_FILES:.cpp=.o)

OBJECTS = $(C_OBJECTS) $(CPP_OBJECTS)


all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

MY_LIBFT_C-main/%.o: MY_LIBFT_C-main/%.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re run