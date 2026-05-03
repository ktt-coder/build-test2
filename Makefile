# Top-level Makefile for C Project

# Variables
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
LIBS =

# Directories
SRC_DIR = src

# Default target
.PHONY: all
all:
	@echo "Building all subdirectories..."
	$(MAKE) -C $(SRC_DIR)/utils all
	$(MAKE) -C $(SRC_DIR)/math all
	$(MAKE) -C $(SRC_DIR)/io all
	$(MAKE) -C $(SRC_DIR)/app all

# Clean build files
.PHONY: clean
clean:
	@echo "Cleaning all subdirectories..."
	$(MAKE) -C $(SRC_DIR)/utils clean
	$(MAKE) -C $(SRC_DIR)/math clean
	$(MAKE) -C $(SRC_DIR)/io clean
	$(MAKE) -C $(SRC_DIR)/app clean

# Run all examples
.PHONY: run
run:
	@echo "Running all examples..."
	$(MAKE) -C $(SRC_DIR)/utils run
	$(MAKE) -C $(SRC_DIR)/math run
	$(MAKE) -C $(SRC_DIR)/io run
	$(MAKE) -C $(SRC_DIR)/app run

# Help target
.PHONY: help
help:
	@echo "Available targets:"
	@echo "  all      - Build all targets"
	@echo "  clean    - Remove build files"
	@echo "  run      - Build and run all examples"
	@echo "  help     - Show this help"
