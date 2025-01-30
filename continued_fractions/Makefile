# compiler options
CC = gcc
CFLAGS = -Wall -c

# source and test files
TEST_DIR = test
SRC_DIR = src

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

clean: 
	rm -rf *.o convergents expansion generalization