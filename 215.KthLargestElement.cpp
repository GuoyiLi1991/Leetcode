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