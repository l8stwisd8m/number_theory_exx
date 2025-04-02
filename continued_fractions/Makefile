# compiler options
CC = gcc
CFLAGS = -Wall -Wpedantic -Wextra

# directories
TEST_DIR = test
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# files
TARGETS = convergents expansion generalization

# targets
all: $(OBJ_DIR) $(BIN_DIR) $(TARGETS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(TARGETS): %: $(OBJ_DIR)/test_cf_%.o $(OBJ_DIR)/cf_%.o $(OBJ_DIR)/cf_utils.o
	$(CC) $(CFLAGS) $^ -o $(BIN_DIR)/$@

# object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c 
	$(CC) $(CFLAGS) -c -o $@ $<

clean: 
	rm -rf $(OBJ_DIR) $(BIN_DIR)
