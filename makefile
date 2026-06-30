# Compiler
CC := gcc

# Dirs
SRC_DIR := src
TEST_DIR := tests
INC_DIR := include
OBJ_DIR := build/obj
BIN_DIR := build/bin

# Outputs
TARGET := $(BIN_DIR)/app
TEST_TARGET := $(BIN_DIR)/tests

# Compilation flags
CFLAGS := \
	-Wall \
	-Wextra \
	-Wpedantic \
	-std=c23 \
	-g \
	-I$(INC_DIR)

LDFLAGS :=

# Source Files
SRC := $(wildcard $(SRC_DIR)/*.c)
# Remove main.c so tests don't get duplicate mains
LIB_SRC := $(filter-out $(SRC_DIR)/main.c,$(SRC))
TEST_SRC := $(wildcard $(TEST_DIR)/*.c)

# Object Files
OBJ := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
LIB_OBJ := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(LIB_SRC))
TEST_OBJ := $(patsubst $(TEST_DIR)/%.c,$(OBJ_DIR)/test_%.o,$(TEST_SRC))

# Targets
.PHONY: all build bear run test clean

all: build

build: $(TARGET)

bear: clean
	bear -- make build

run: build
	@./$(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	@echo "Cleaning Project"
	@rm -rf build
	@echo "./build folder removed"
	@echo "clean complete"

# Link application
$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $^ -o $@ $(LDFLAGS)


# Link tests
$(TEST_TARGET): $(LIB_OBJ) $(TEST_OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $^ -o $@ $(LDFLAGS)

# Compile App
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile Tests
$(OBJ_DIR)/test_%.o: $(TEST_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
