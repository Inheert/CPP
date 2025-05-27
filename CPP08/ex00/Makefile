# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 09:08:23 by tclaereb          #+#    #+#              #
#    Updated: 2025/05/27 09:30:02 by tclaereb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

INCLUDES = -I ./includes/

SRC_DIR = .
BIN_DIR = ./bin

SOURCES = main.cpp utils/Log/Log.cpp

OBJECTS = $(addprefix $(BIN_DIR)/,$(SOURCES:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CXX) $(OBJECTS) -o $@

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@rm -rf $(BIN_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
