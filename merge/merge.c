typedef long long LONG64;

static void merge (LONG64*, LONG64, LONG64, LONG64*);
static void recursive (LONG64*, LONG64, LONG64, LONG64*);

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
void MergeSort (LONG64* data, LONG64 length) {
	LONG64 temp [length];
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
static void recursive (LONG64* data, LONG64 start, LONG64 end, LONG64* temp) {	
	LONG64 m = start + (end - start) / 2;
	LONG64 i;
	if ((end - start) > 1) {
		recursive(data, start, m, temp);
		merge(data, start, m, temp);
		recursive(data, m, end, temp);
		merge(data, m, end, temp);
	}
}

static void merge (LONG64* data, LONG64 start, LONG64 end, LONG64* temp) {
	LONG64 m = start + (end - start) / 2;
	LONG64 tid = start, i = start, j = m;
	while (i < m && j < end) {
		temp[tid++] = (data[i] < data[j]) ? data[i++] : data[j++];
	}
	while (i < m) { temp[tid++] = data[i++]; }
	while (j < end) { temp[tid++] = data[j++]; }
	for (i = start; i < end; i++) {
		data[i] = temp[i];
	}
}

