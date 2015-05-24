static void merge (int*, int, int, int*);
static void recursive (int*, int, int, int*);

/**
 * MergeSort
 * 
 * @param *data - integer array to be sorted.
 * @param length - number of integers in the array.
 *
 * @notes
 * This function acts as a buffer between calling MergeSort and calling the
 * recursive operation by allocating temporary stack memory and initiating
 * the recursive process.
 */
void MergeSort (int* data, int length) {
	int temp [length];
	recursive(data, 0, length, temp);
	merge(data, 0, length, temp);
}

/**
 * recursive
 *
 * @param *data - integer array to be sorted.
 * @param start - starting position of array to sort.
 * @param end - ending position of array to sort.
 * @param *temp - temporary memory for storing sorted merge operations.
 *
 * @notes
 * Recursively merges the left-then-right subtrees. Notice that we do not 
 * actually merge the entire thing after we are done. This is because when
 * recursion backtracks we're going to merge the result immediately (unless we
 * are at the final stage, in which case we need to manually merge).
 *
 * This saves a substantial amount of unnecessary merge operations.
 */
static void recursive (int* data, int start, int end, int* temp) {	
	int m = start + (end - start) / 2;
	int i;
	if ((end - start) > 1) {
		recursive(data, start, m, temp);
		merge(data, start, m, temp);
		recursive(data, m, end, temp);
		merge(data, m, end, temp);
	}
}

static void merge (int* data, int start, int end, int* temp) {
	int m = start + (end - start) / 2;
	int tid = start, i = start, j = m;
	while (i < m && j < end) {
		temp[tid++] = (data[i] < data[j]) ? data[i++] : data[j++];
	}
	while (i < m) { temp[tid++] = data[i++]; }
	while (j < end) { temp[tid++] = data[j++]; }
	for (i = start; i < end; i++) {
		data[i] = temp[i];
	}
}

