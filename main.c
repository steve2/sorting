#include <stdio.h>
#include <time.h>
#include "selection.h"
#include "merge.h"

void randomize (int *data, int start, int end, int range) {
	int i;
	for (i = start; i < end; i++) {
		data[i] = rand() % range + 1;
	}
}

void arrayPrint (int *data, int length) {
	int i;
	printf("\nPrinting array of length %d.\n", length);
	for (i = 0; i < length; i++) {
		printf("  [%d]\t%d\n", i, data[i]);
	}
}

void arrayCopy (int *data, int *copy, int length) {
	int i;
	for (i = 0; i < length; i++) {
		copy[i] = data[i];
	}
}

int main (int argc, char *argv[]) {
	int size = strtol(argv[1], NULL, 10);
	int data[size];
	int merged[size];
	
	srand(time(NULL));
	randomize(data, 0, size, strtol(argv[2], NULL, 10));
	arrayPrint(data, size);
	
	printf("\nPerforming MergeSort...\n");
	printf("-----------------------\n");
	MergeSort(data, size);
	arrayPrint(data, size);

	return 0;
}