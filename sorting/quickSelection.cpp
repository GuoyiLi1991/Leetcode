// 1. Take O(n) time on average to 
// 	 return the k-th largest element in an unsorted array.
// 2. Similar to quick sort.
// 3. Randomly select a pivot and make sure
//    all elements that left to pivot is smaller than it
//    all elements that right to pivot is larger than it.
int quick_select(vector<int> A, int left, int right, int k) {
	if (left >= right)
		return A[left];

	int index = partition(A, left, right);
	int size = index - left + 1;
	if (size == k)
		return A[left + k - 1];

	if (size > k)
		return quick_select(A, left, index -1, k);
	else
		return quick_select(A, index + 1, right, k - size);
}

int partition(vector<int>& A, int left, int right) {
	int pivot = A[right];
	while (left != right) {
		while (A[left] < pivot && left < right) 
			left++;
		if (left < right)
			swap(A[left], A[right--]);

		while (A[right] > pivot && left < right)
			right++;
		if (left < right)
			swap(A[left++], A[right]);
	}
	
	return left;
}