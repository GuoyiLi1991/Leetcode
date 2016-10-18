// Min-heap: O(nlogk)???
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       // sort(nums.begin(), nums.end());
       // return(*(nums.end()-k));
        priority_queue<int> maxPQ(nums.begin(), nums.end());
       for (int i=1; i<k; i++)
       {
           maxPQ.pop();
       }
       return maxPQ.top();
        
    }
};


///////////////
// Quick selection
// O(n)  ~350ms
class Solution {
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        // ??? faster if (pivot = nums[left], swap(nums[left], nums[right]);)
        int index = left;
        for (int i = left; i < right; i++) {
            if (nums[i] >= pivot)
                swap(nums[i], nums[index++]);
        }
        swap(nums[index], nums[right]);
        return index;
    }
    
    int quick_select(vector<int>& nums, int left, int right, int k) {
        if (left >= right)
            return nums[left];
            
        int index = partition(nums, left, right);
        int abs_idx = left + k - 1;
        if (index == abs_idx) 
            return nums[index];
        if (index > abs_idx)  
            return quick_select(nums, left, index - 1, k);
        else 
            return quick_select(nums, index + 1, right, abs_idx - index);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quick_select(nums, 0, nums.size() - 1, k);
    }
};