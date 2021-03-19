// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

class Solution
{
    static const int COOLDOWN = 1;
    
public:
    int maxProfit(vector<int>& prices)
    {
        if(prices.size() <= 1)
        {
            return 0;
        }
        
        if(prices.size() == 2)
        {
            int profit = prices[1] - prices[0];
            return max(profit, 0);
        }
        
        int results[prices.size()][2];
        
        results[0][0] = 0;          // didn't buy first stock
        results[0][1] = -prices[0]; // did buy the first stock
        
        // either buy the stock on day 1 and sell it right away or don't buy it on day 1 or 2
        results[1][0] = max(results[0][1] + prices[1], results[0][0]);
        
        // either buy the stock day 2 or keep the stock we bought day 1
        results[1][1] = max(-prices[1], results[0][1]);
        
        for(int i = 2; i < prices.size(); i++)
        {
            // either sold the stock today or didn't have have and don't buy
            results[i][0] = max(results[i-1][1] + prices[i], results[i-1][0]);
            
            // either buy a stock today or hold the one from yesterday
            results[i][1] = max(results[i-1-COOLDOWN][0] - prices[i], results[i-1][1]);
        }
        
        return results[prices.size()-1][0];
    }
};
