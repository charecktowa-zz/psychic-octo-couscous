# A simple Makefile for compiling

# set the compiler
CC := clang

# set the compiler flags
CFLAGS := `sdl2-config --libs --cflags` -std=c17 -Wall -Wextra -lSDL2_image -lm

# add header files here
HDRS :=

# add source files ere
SRCS := src/main.c

# generate names of object files
OBJS := $(SRCS:.c=.o)

# name of executable
EXEC := game

# default recipe
all: $(EXEC)

# recipe for building the final executable
$(EXEC): $(OBJS) $(HDRS) Makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS)

# Cleans the workspace
clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all clean
