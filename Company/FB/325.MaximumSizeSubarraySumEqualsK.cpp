// Sol1 : Brute force O(n^2)
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        if (n > 1000) return 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum == k) {
                    if (res < j - i + 1)
                        res = j - i + 1;
                }
            }
        }
        return res;
    }
};

/////////////
// Sol 2: Using hash table
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;
        int res = 0;
        int cur_sum = 0;
        unordered_map<int, int> ht; //<num, index>

        for (int i = 0; i < n; i++) {
            cur_sum += nums[i];
            
            if (cur_sum == k) // 0 to i
                res = max(res, i - 0 + 1);
            
            if (ht.find(cur_sum - k) != ht.end()) { //ht[cur_sum - k] + 1 to i
                //explaination: cur_sum is sum[0, j], ht[i] is sum[0, i], sum[0, j] - sum[0, i] = sum[i+1, j] should be k
                res = max(res, i - ht[cur_sum - k]);
            }

            if (ht.find(cur_sum) == ht.end()) //store only the earliest time it reaches cur_sum
                ht[cur_sum] = i;
        }
        return res;
    }
};