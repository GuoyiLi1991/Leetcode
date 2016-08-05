class Solution {
    // recursive DFS with prunning
    void DFS (vector<int>& coins, int& curMin, int amount, int tmp_count, int idx) {
        if (idx == coins.size())
            return;
            
        int number = amount /coins[idx]; //minimum possible if only take the largest ones
        for (int i = number; i >= 0; i--) {
            int remain = amount - i * coins[idx];
            int newcount = tmp_count + i;
            if (remain > 0 && newcount < curMin)
                DFS(coins, curMin, remain, newcount, idx+1);  //add smaller
            else if (newcount < curMin)
                curMin = newcount;
            else break;
        }
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if (n == 0 || amount == 0)
            return 0;
        sort(coins.begin(), coins.end(), std::greater<int>()); //sorting in descending order of coin values
        int curMin = INT_MAX;
        DFS(coins, curMin, amount, 0, 0);
        return (curMin == INT_MAX)? -1:curMin;
    }
};


