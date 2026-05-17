#include "libhash.h"

int main(void) {

	Node *hash[SIZE_HASH];
	start_hash(hash);
	if (load_hash(hash) == 1) {
		return 1;
	}

	print_hash(hash);
	free_hash(hash);
	return 0;
}
