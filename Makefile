OBJS = src/main.c

CC = clang-8

COMPILER_FLAGS = -std=c18 -O2 -Wall -Wextra -Wpedantic -v

LINKER_FLAGS = -lSDL2

OBJ_NAME = build/game

# headers
HDR_GAME = src/game.c
HDR_HNDLR = src/exception.c

all : 
		$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME) $(OBJS) $(HDR_GAME) $(HDR_HNDLR)

# clang-8 -std=c18 -O2 -Wall -Wextra -Wpedantic -v -o game src/main.c