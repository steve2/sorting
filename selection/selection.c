void SelectionSort (long long *data, long long length) {
	long long i, j, temp, lowest;
	for (i = 0; i < length; i++) {
		lowest = i;
		for (j = i + 1; j < length; j++) {
			if (data[j] < data[lowest]) {
				lowest = j;
			}
		}
		temp = data[i];
		data[i] = data[lowest];
		data[lowest] = temp;
	}
}