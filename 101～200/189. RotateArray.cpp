class Solution {
public:
    //sol1: O(n) time, O(1) space
    void rotate1(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.end());
        k = k % (nums.size());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }

    //sol2: O(n) time, O(n) space
    void rotate2(vector<int>& nums, int k) {
        int n = nums.size();
        if (k % n == 0 || k < 0)
            return;
        //make a copy
        vector<int> cpy(nums);
        
        for (int i = 0; i< n; i++)
        {
            nums[(i+k) % n] = cpy[i];
        }
    }

    //sol3: O(n) time, O(1) space  
    // "Juggling Algorithm" ?
    void rotate3(vector<int>& nums, int k) {
    	int n = nums.size();
    	k = k % n;
    	//corner case
    	if (n < 2 || k < 1) 
    		return;
    	for (int i = k; n > 0; ++i) {
    		int j = i, prev = num[(i-k) % k];
    		while (n-- > 0) {
    			swap(prev, nums[j]);
    			j = (j+k) % nums.size();
    			if (j == i)
    				break;
    		}
    	}
    }
};

// Sol4: O(n) time, O(1) space
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (k % n == 0) return;
        for (int i = 0; i < k; i++) {
            nums.insert(nums.begin(), nums.back());
            nums.pop_back();
        }
    }
};
