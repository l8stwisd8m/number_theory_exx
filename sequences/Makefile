# compiler options
CC = gcc
CFLAGS = -Wall -Wpedantic -Wextra

# directories
TEST_DIR = test
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# files
TARGETS = sb_tree cw_tree fs_tree

# targets
all: $(OBJ_DIR) $(BIN_DIR) $(TARGETS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

sb_tree: $(OBJ_DIR)/tree.o $(OBJ_DIR)/stern_brocot.o $(OBJ_DIR)/stern_brocot_tree.o
	$(CC) $(CFLAGS) $^ -o $(BIN_DIR)/$@

cw_tree: $(OBJ_DIR)/tree.o $(OBJ_DIR)/calkin_wilf.o $(OBJ_DIR)/calkin_wilf_tree.o
	$(CC) $(CFLAGS) $^ -o $(BIN_DIR)/$@

fs_tree: $(OBJ_DIR)/tree.o $(OBJ_DIR)/farey_tree.o $(OBJ_DIR)/stern_brocot.o
	$(CC) $(CFLAGS) $^ -o $(BIN_DIR)/$@

# object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c 
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
