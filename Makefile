##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Core Makefile
##

SRC			= 	src/main.cpp \
				src/Game/Game.cpp \
				src/Menu/Menu.cpp \
				src/button/button.cpp \

CXX_OBJS			= $(SRC:.cpp=.o)

NAME		= OpenThisFuckingDoor

INCLUDE 	= -I./src/Game/ -I./src/ -I./src/Menu -I./src/button
GRAPHFLAG	= -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
CXXFLAGS 	= -std=c++20 -Wall -Wextra -Werror -g $(INCLUDE) $(GRAPHFLAG)

all: $(NAME)

$(NAME): $(CXX_OBJS)
	g++ -o $(NAME) $(CXX_OBJS) $(CXXFLAGS)

clean:
	rm -f $(CXX_OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all
