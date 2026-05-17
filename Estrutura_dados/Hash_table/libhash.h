#ifndef LIBHASH_H
#define LIBHASH_H

#define SIZE_WORD 10
#define SIZE_HASH 26

typedef struct Node {
	char word[SIZE_WORD];
	struct Node *next;
} Node;

int load_hash(Node *hash[SIZE_HASH]);
int check_node(Node *node);
int check_index_word(Node *node);
void start_hash(Node *hash[SIZE_HASH]);
void print_hash(Node *hash[SIZE_HASH]);
void free_hash(Node *hash[SIZE_HASH]);
void print_words(Node *hash[SIZE_HASH]);

#endif
