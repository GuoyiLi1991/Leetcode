class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size()<2) return 0;
        int buy =prices[0], sell = prices[1], profit = sell-buy;
        for (int i = 2; i<prices.size(); i++)
        {
            buy = min(prices[i-1],buy);
            profit = max(profit, prices[i] - buy);
        }
        
        return profit<0? 0:profit;
        
        
    }
};