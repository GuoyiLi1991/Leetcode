class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)  
            return;
         
         // next permutation must be smallest larger number than current    
        //start from right, find the first descending edge
        int i;
        for (i = n - 2; i >= 0; i--) {
            if (nums[i + 1] > nums[i])
                break;
        }
        int edge = i;
        
        
        if (edge >= 0) {
            for (i = n - 1; i > edge; i--) {
                if (nums[i] > nums[edge])
                    break;
            }
            swap(nums[i], nums[edge]);
        }
        
        // reverse number [edge + 1, ...., n)
        int j = n - 1;
        int k = edge + 1;
        while (k < j) {
            swap(nums[k], nums[j]);
            k++; 
            j--;
        }
        
    }
};