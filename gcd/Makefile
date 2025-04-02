# compiler options
CC = gcc
CFLAGS = -Wall -Wpedantic -Wextra

# directories
TEST_DIR = test
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# files
TARGETS = bezout binary_bezout

# targets
all: $(OBJ_DIR) $(BIN_DIR) $(TARGETS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

bezout: $(OBJ_DIR)/bezout.o $(OBJ_DIR)/gcd.o $(OBJ_DIR)/extended_gcd.o
	$(CC) $(CFLAGS) $^ -o $(BIN_DIR)/$@

binary_bezout: $(OBJ_DIR)/binary_bezout.o $(OBJ_DIR)/binary_gcd.o $(OBJ_DIR)/binary_extended_gcd.o
	$(CC) $(CFLAGS) $^ -o $(BIN_DIR)/$@

# object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c 
	$(CC) $(CFLAGS) -c -o $@ $<

clean: 
	rm -rf $(OBJ_DIR) $(BIN_DIR)
