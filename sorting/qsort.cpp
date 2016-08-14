void qSort(int array[], int left, int right) {
	if (left >= right)
		return;
	int idx = partition(array, left, right);
	qSort(array, left, idx - 1);
	qSort(array, idx + 1, right);
}

// int partition(int array[], int left, int right) {
// 	int pivot = array[right];
// 	while (left != right) {
// 		while (array[left] < pivot && left < right)
// 			left++;
// 		if (left < right)
// 			swap(array[left], array[right--]);

// 		while (array[right] > pivot && left < right)
// 			right--;
// 		if (left < right)
// 			swap(array[left++], array[right]);
// 	}
// 	return pivot;
// }

int partition(int A[], int left, int right) {
	int pivot = A[right];
	int pIndex = left;
	for (int i = left; i < right; i++) {
		if (A[i] <= pivot) {
			swap(A[i], A[pIndex]);
			pIndex++;
		}
	}
	swap(A[pIndex], A[right]);
	return pIndex;
}