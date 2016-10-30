// Sol1. Brute force, find max for each k window
// Time O(nk)


// Sol2. Maintain a maxHeap, be careful about duplication
// Trick: use multiset to implement the heap with duplicated key
// For pq, we have pq.push(val), pq.pop(), pq.top()
// For ms, we have ms.insert(val), ms.erase(itr)/ ms.erase(val), *ms.rbegin()
// Time O(nlogk)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        if (k <= 0) return res;
        if (k == 1) return nums;
        
        // maintain a maxHeap of size k
        // since we want to update cur max often
        multiset<int> maxHeap;
        int i;
        for (i = 0; i < k; i++) {
            maxHeap.insert(nums[i]);
        }
        res.push_back(*maxHeap.rbegin());
        
       // i--; //end of window
        while (i < n) {
            int start = i - k;
            maxHeap.erase(maxHeap.find(nums[start])); //make sure it only removes one copy
            //maxHeap.erase(--maxHeap.end()); not work because we want not only to remove the largest
            //maxHeap.erase(nums[start]); not work because of duplication
            maxHeap.insert(nums[i]);
            res.push_back(*maxHeap.rbegin());
            i++;
        }
        
        return res;
        
    }
};
