# compiler options
CC = gcc
CFLAGS = -Wall -c

# source and test files
TEST_DIR = test
SRC_DIR = src
UTILS_SRC = $(SRC_DIR)/cf_utils.c
EXPANSION_SRC = $(SRC_DIR)/cf_expansion.c
CONVERGENTS_SRC = $(SRC_DIR)/cf_convergents.c
GENERALIZATION_SRC = $(SRC_DIR)/cf_generalization.c

# targets
all: convergents expansion generalization

convergents: test_cf_convergents.o cf_convergents.o cf_utils.o
	$(CC) $^ -o $@

expansion: test_cf_expansion.o cf_expansion.o cf_utils.o
	$(CC) $^ -o $@

generalization: test_cf_generalization.o cf_generalization.o cf_utils.o
	$(CC) $^ -o $@

# object files
%.o: $(TEST_DIR)/%.c
	$(CC) $< $(CFLAGS)

%.o: $(SRC_DIR)/%.c
	$(CC) $< $(CFLAGS)

cf_utils.o: $(UTILS_SRC)

clean: 
	rm -rf *.o convergents expansion generalization
