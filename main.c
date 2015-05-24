#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "selection/selection.h"
#include "merge/merge.h"

#define SUCCESS 1
#define FAILURE 0
typedef long long LONG64;

void randomize (LONG64 *data, LONG64 start, LONG64 end, LONG64 range) {
	LONG64 i;
	for (i = start; i < end; i++) {
		data[i] = rand() % range + 1;
	}
}

void arrayPrint (LONG64 *data, LONG64 length) {
	LONG64 i;
	printf("\nPrinting array of length %lld.\n", length);
	for (i = 0; i < length; i++) {
		printf("  [%lld]\t%lld\n", i, data[i]);
	}
}

int main (int argc, char *argv[]) {
	LONG64 size;
	LONG64* data;
	clock_t start, stop;
	
	if (argc == 3) {
		size = strtol(argv[1], NULL, 10);
		data = (LONG64*) malloc(sizeof(LONG64) * size);
		
		srand(time(NULL));
		printf("Size: %lld\n", size);
		randomize(data, 0, size, strtol(argv[2], NULL, 10));
		
		printf("\nPerforming MergeSort...\n");
		printf("-----------------------\n");
		MergeSort(data, size);
		printf("MergeSort sorted completed.\n");
	
		free(data);
		return SUCCESS;
	} else {
		printf("Incorrect usage, correct usage: %s 50 10\n", argv[0]);
		return FAILURE;
	}
}