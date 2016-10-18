//////////
// Only conduct one transaction
// Sol1: record lowest until i-th pos
class Solution {
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;

        int maxProfit = 0;
        int lowest = prices[0]; //lowest buying until i
        for (int i = 1; i < n; i++) {
            maxProfit = max(maxProfit, prices[i] - lowest);
            lowest = min(lowest, prices[i]);
        }

        return maxProfit;
    }
};
    

//////////
// Sol2: record max profit in each subarray
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        
        int maxGlobal = 0, maxLocal = 0;
        for (int i = 1; i < n; i++) {
            int change = prices[i] - prices[i - 1];
            maxLocal = max(maxLocal + change, 0);//maximum profit in the new subarray
            maxGlobal = max(maxLocal, maxGlobal);
        }
        
        return maxGlobal;
    }
};