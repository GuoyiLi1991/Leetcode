//https://leetcode.com/discuss/76146/trade-off-in-this-problem-should-be-considered

class TwoSum {
    unordered_multiset<int> nums;
public:

    // Add the number to an internal data structure.
	void add(int number) {
	    nums.insert(number);
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for (int x:nums)
	    {
	        int cnt = 0;
	        if (x == value-x) cnt = 1;
	 
	        if (nums.count(value-x) > cnt ) 
	            return true;
	    }
	    return false;
	}
};

// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);