# A simple Makefile

# Set te compiler
CC := clang

# Compiler flags
CFLAGS := gcc `sdl2-config --libs --cflags` -std=c17 -Wall -Wextra -lSDL2_image -lm

# add header files
HDRS :=

# 