// 非比较型排序, 需要事先知道数组内元素最大值max
// 时间复杂度：O(max + n), 适用于max << n的情况
// 空间复杂度：O(max + n), 用于记录桶计数count[max]和原始数组副本tmpA[n]
void BucketSort(vector<int>& A, int n, int max) {
	// @parm A[]: array to be sorted
	// @parm n: length of A[]
	// @parm max: all elements in A[] is in range [0, max)

	vector<int> tmpA(A);  //size n
	vector<int> count(max, 0);
	for (int i = 0; i < n; i++)
		count [A[i]]++;  // put elements into the buckets

	for (int i = 1; i < max; i++)
		count[i] = count[i] + count[i-1];
	//count[i] saves the starting index(saved in array) of value i+1

	//for value tmpA[i], the last index should be count[tmpA[i]] - 1
	for (int i = n - 1; i >= 0; i--)
		A[--count[tmpA[i]]] = tmpA[i];
}