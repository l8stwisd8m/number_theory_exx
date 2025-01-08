# compiler options
CC = gcc
CFLAGS = -Wall -o

# targets
all: convergents expansion generalization

convergents: test_cf_convergents.c
	$(CC) $(CFLAGS) convergents test_cf_convergents.c

expansion: test_cf_expansion.c
	$(CC) $(CFLAGS) expansion test_cf_expansion.c

generalization: test_cf_generalization.c
	$(CC) $(CFLAGS) generalization test_cf_generalization.c
