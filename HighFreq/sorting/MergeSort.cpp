// 时间复杂度 O(nlogn)
// 空间复杂度： 数组（O(n)), 链表O(1)

void merge_sort(int array[], int helper[], int left, int right) {
	// Recursion
	// Base case
	if (left >= right)
		return;
	// Recursive step: divide into left and right parts
	// 	Both parts will be sorted with merge_sort()
	int mid = left + (right - left)/2;
	merge_sort(array, helper, left, mid);
	merge_sort(array, helper, mid + 1, right);

	// Conquer: Combine two parts into one
	for (int i = left; i <= right; i++)
		helper[i] = array[i];

	int ll = left, rr = mid + 1;
	int cur = left;
	while (ll <= mid && rr <= right) { // while ll and rr not meet the end
		array[cur++] = (helper[ll] <= helper[rr])? 
							helper[ll++]; helper[rr++];
	}

	//if left part has some large element remaining
	while (ll <= mid)
		array[cur++] = helper[ll++];
	// no need to check right part: even if there is element remaining,
	// they are already in the right place.
}
