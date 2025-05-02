# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/24 19:28:25 by samusanc          #+#    #+#              #
#    Updated: 2025/05/02 14:03:11 by samusanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Matrix
CXXFLAGS	=	-g -Wall -Wextra -Werror -I ./
CXX		=	c++ $(CXXFLAGS)
MAIN		=	./main.cpp
INC		=	./Matrix.hpp \
			./Tensors.hpp \
			./Vector.hpp \

SRCS		=	$(MAIN) \
			./Tensors.cpp \
			./Matrix.cpp \
			./Vector.cpp \

O_DIR		=	./objects/
OBJS		=	$(addprefix $(O_DIR)/, $(SRCS:.cpp=.o))

$(O_DIR)/%.o: %.cpp
	mkdir -p $(@D)
	$(CXX) -c $< -o $(O_DIR)/$(<:.cpp=.o)

all: $(NAME) $(SRCS)

$(NAME): $(OBJS) $(INC)
	$(CXX) $(OBJS) -o $(NAME)

re: fclean all

fclean: clean
	@rm -f $(NAME)
	@rm -rf objects

clean:
	@rm -f $(OBJS)

.PHONY: all
