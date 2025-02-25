NAME = a.out

CC = c++

CFLAGS = -Wall -Wextra -Werror -g3 -std=c++98

INCLUDES = -I ./includes/

SRC_DIR = .
BIN_DIR = ./bin

SOURCES = main.cpp utils/Log/Log.cpp \
			A_Animal/A_Animal.cpp Dog/Dog.cpp \
			Cat/Cat.cpp Brain/Brain.cpp

OBJECTS = $(addprefix $(BIN_DIR)/,$(SOURCES:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(OBJECTS) -o $@

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@rm -rf $(BIN_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
