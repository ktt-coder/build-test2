# Makefile for io directory

# Variables
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
LIBS =

# Find all source files
SRCS = $(wildcard *.c)
TARGETS = $(SRCS:.c=)

# Default target
.PHONY: all
all: $(TARGETS)

# Build targets
%: %.c
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

# Clean build files
.PHONY: clean
clean:
	rm -f $(TARGETS)

# Run examples
.PHONY: run
run: all
	@echo "Running io examples..."
	./file_reader

# Help target
.PHONY: help
help:
	@echo "Available targets:"
	@echo "  all      - Build all targets"
	@echo "  clean    - Remove build files"
	@echo "  run      - Build and run all examples"
	@echo "  help     - Show this help"
