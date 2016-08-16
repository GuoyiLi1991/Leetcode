// when max is large, use RadixSort() to do BucketSort() for k times
// O(K * N), k is the number of digets/ length of string
// 将数据看作有限进制数，针对每一位进行一次BucketSort()
// 字典序从左到右（高位到地位），数值序从右到左（地位到高位）

void RadixSort(vector<int> A, int digits, int radix) {
	// n is the length of the array
	// digits is the number of digits
	int *tmpA = new int[n];
	int *count = new int[radix]; //radix bucket

	int i, j, k;
	int Radix = 1; //radix modulo, used to get the ith digit of A[j]

	//for i-th digit
	for (i = 1; i <= digits; i++) {
		//initialize counter
		for (j = 0; j < radix; j++)
			count[j] = 0; 

		//put elements into bucket j, j from 0 to n-1
		for (j = 0; j < n; j++) {	
			k = (A[j] / Radix) % radix; //get a digit
			count[k]++;
		}

		//count elements in the buckets
		for (j = 1; j < radix; j++) {
			count[j] = count[j-1] + count[j];
		}

		//bucket sort
		for (j = n-1; j >= 0; j--) {
			k = (Array[j] / Radix) % radix;
			count[k]--;
			tmpA[count[k]] = A[j];
		}

		//copy data back to array
		for (j = 0; j < n; j++) 
			A[j] = tmpA[j];

		Radix *= radix; //get the next digit
	}
}