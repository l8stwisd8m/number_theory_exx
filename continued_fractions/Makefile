# compiler options
CC = gcc
CFLAGS = -Wall -c

# targets
all: convergents expansion generalization

convergents: test_cf_convergents.o cf_convergents.o cf_utils.o
	$(CC) test_cf_convergents.o cf_convergents.o cf_utils.o -o convergents
test_cf_convergents.o: test/test_cf_convergents.c
	$(CC) test/test_cf_convergents.c $(CFLAGS)
cf_convergents.o: src/cf_convergents.c
	$(CC) src/cf_convergents.c $(CFLAGS)

expansion: test_cf_expansion.o cf_expansion.o cf_utils.o
	$(CC) test_cf_expansion.o cf_expansion.o cf_utils.o -o expansion
test_cf_expansion.o: test/test_cf_expansion.c
	$(CC) test/test_cf_expansion.c $(CFLAGS)
cf_expansion.o: src/cf_expansion.c
	$(CC) src/cf_expansion.c $(CFLAGS)

generalization: test_cf_generalization.o cf_generalization.o cf_utils.o
	$(CC) test_cf_generalization.o cf_generalization.o cf_utils.o -o generalization
test_cf_generalization.o: test/test_cf_generalization.c
	$(CC) test/test_cf_generalization.c $(CFLAGS) 
cf_generalization.o: src/cf_generalization.c
	$(CC) src/cf_generalization.c $(CFLAGS)

cf_utils.o: src/cf_utils.c #common target
	$(CC) src/cf_utils.c $(CFLAGS)

clean: 
	rm -rf *.o convergents expansion generalization
