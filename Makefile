# Compiler and flags
CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -g

# Source files and output
SRC = src/main.c src/file_operations.c src/directory_ops.c src/permissions.c src/logger.c
OBJ = $(SRC:.c=.o)
OUTPUT = bin/file_manager

# Default target
all: $(OUTPUT)

# Build executable
$(OUTPUT): $(SRC)
	mkdir -p bin
	$(CC) $(CFLAGS) -o $(OUTPUT) $(SRC)

# Clean target
clean:
	rm -rf $(OBJ) $(OUTPUT)

# Run program
run: all
	./$(OUTPUT)

# Phony targets
.PHONY: all clean run

