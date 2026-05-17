CC = gcc
CFLAGS = -Wall -Wextra -g

all: Hash_Table

Hash_Table: Hash_Table.o libhash.o
	$(CC) $(CFLAGS) -o Hash_table Hash_Table.o libhash.o
	
Hash_Table.o: Hash_Table.c libhash.h
	$(CC) $(CFLAGS) -c Hash_Table.c

libhash.o: libhash.c libhash.h
	$(CC) $(CFLAGS) -c libhash.c

clean: 
	rm -f *.o Hash_Table
