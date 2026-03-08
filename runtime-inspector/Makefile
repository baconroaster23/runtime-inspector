# Compiler
CC = gcc

# Project name
TARGET = inspector

# Directories
SRC_DIR = src
INC_DIR = include
SCRIPT_DIR = scripts
BUILD_DIR = build

# Compiler flags
CFLAGS = -I$(INC_DIR) -Wall -Wextra -O2

# Libraries
LIBS = -llua5.4 -lncurses

# Source files
SRC = $(wildcard $(SRC_DIR)/*.c)

# Object files
OBJ = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))

# Default rule
all: directories $(TARGET)

# Create build directory
directories:
	mkdir -p $(BUILD_DIR)

# Build executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LIBS)

# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Run program
run: $(TARGET)
	@echo "Running Runtime Inspector..."
	sudo ./$(TARGET)

# Run Lua example script
run-lua: $(TARGET)
	@echo "Running Lua script..."
	sudo ./$(TARGET) scripts/example.lua

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Rebuild everything
rebuild: clean all

# Install dependencies (Debian/Kali/Ubuntu)
deps:
	sudo apt update
	sudo apt install -y build-essential liblua5.4-dev libncurses5-dev

# Show help
help:
	@echo "Runtime Inspector Build System"
	@echo ""
	@echo "make           -> build program"
	@echo "make run       -> run inspector"
	@echo "make run-lua   -> run Lua example script"
	@echo "make clean     -> remove compiled files"
	@echo "make rebuild   -> clean + rebuild"
	@echo "make deps      -> install dependencies"