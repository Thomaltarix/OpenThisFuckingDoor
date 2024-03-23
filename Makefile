##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Core Makefile
##

SRC			= 	src/main.cpp \
				src/Game/Game.cpp \
				src/Modules/HitboxModule.cpp \
				src/Modules/MovementModule.cpp \
				src/Modules/CollisionModule.cpp \
				src/Modules/DisplayModule.cpp \
				src/Modules/TimeModule.cpp \
				src/Modules/RotatableModule.cpp \
				src/Modules/PositionModule.cpp \
				src/GameMenu/GameMenu.cpp \
				src/button/button.cpp \

CXX_OBJS			= $(SRC:.cpp=.o)

NAME		= OpenThisFuckingDoor

INCLUDE 	= -I./src/Game/ -I./src/ -I./src/Modules -I./src/GameMenu -I./src/button
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
