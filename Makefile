# Makefile for compiling and linking C and C++ files into an executable

# Compiler settings
CXX = clang++
CC = clang
CXXFLAGS = -Wall -g
LDFLAGS =

# Directories
SRC_DIR = src
OBJ_DIR = obj

# Find all .cpp and .c files in the source directory
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/*.c)

# Create object files list by replacing .cpp and .c extensions with .o
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
OBJ_FILES := $(OBJ_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Output executable name
EXEC = lice.exe

# Phony targets
.PHONY: all run clean

# Default target: build everything
all: $(EXEC)

# Rule to link object files into the final executable
$(EXEC): $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) -o $(EXEC) $(LDFLAGS)

# Rule to compile C++ files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to compile C files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CXXFLAGS) -c $< -o $@

# Run the compiled program
run: $(EXEC)
	@./$(EXEC)

# Clean up generated files
clean:
	rm -rf $(OBJ_DIR)/*.o $(EXEC)
