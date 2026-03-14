##
# Cpp_mod3 - ex00
#
# @file
# @version 0.1


NAME=serialize
CC=c++
CFLAGS=-Wall -Werror -Wextra -std=c++98

SRC = Serializer.cpp \
      main.cpp
OBJ=$(SRC:.cpp=.o)

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(NAME) compiled"

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -f *.o
	@echo "object files cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "executable file, $(NAME), cleaned"

re: fclean all

.PHONY: all clean fclean re

# end
