OBJS = src/main.c

CC = clang-8

COMPILER_FLAGS = -std=c18 -O2 -Wall -Wextra -Wpedantic -v

LINKER_FLAGS = -lSDL2

OBJ_NAME = build/game

# headers
HDR_NAME = src/game.c

all : 
		$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME) $(OBJS) $(HDR_NAME)

# clang-8 -std=c18 -O2 -Wall -Wextra -Wpedantic -v -o game src/main.c