NAME = a.out

CC = g++

COMPILER = ./compiler

CFLAGS = -Wall -Wextra -Werror -std=c++98

INCLUDES = -I ./includes/

SRC_DIR = .
BIN_DIR = ./bin

SOURCES = main.cpp Fixed/Fixed.cpp utils/log.cpp
SOURCE_COUNT := $(words $(SOURCES))
COUNT = 1

OBJECTS = $(addprefix $(BIN_DIR)/,$(SOURCES:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(OBJECTS) -o $@

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@bash make_compiler.sh $(SOURCE_COUNT) $(COUNT) $< $@
	$(eval COUNT := $(shell echo $$(($(COUNT) + 1))))
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@rm -rf $(BIN_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
