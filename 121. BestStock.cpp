class Solution {
    int sol1(vector<int>&prices)
    {
        int n = prices.size();
        if (n < 2) return 0;  // no chance to sell the stock
        
        int minprice = prices[0];
        int maxprof = 0;
        
        for (int i = 1; i < n; i++)
        {
            minprice = min(prices[i], minprice);    //record lowest buy price so far
            maxprof = max(maxprof, prices[i] - minprice);
        }
        
        return maxprof;
    }
    
    int sol2(vector<int>& prices)  //Kadane's Algorithm, Maximum subarray problem
    {
        int n = prices.size();
        if (n < 2) return 0;
        
        int maxLocal = 0, maxGlobal = 0;
        
        for (int i = 1; i < n; i++)
        {
            int diff = prices[i] - prices[i-1];
            maxLocal = max(0, maxLocal + diff);
            maxGlobal = max(maxLocal, maxGlobal);
        }
        
        return maxGlobal;
    }
public:
    int maxProfit(vector<int>& prices) {
        
       // return sol1(prices);
       return sol2(prices);
    }
};