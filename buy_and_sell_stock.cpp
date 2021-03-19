// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

class Solution
{
    vector<optional<int>> m_maxBuyCache;
    vector<optional<int>> m_maxSellCache;
    
public:
    int maxProfit(vector<int>& prices)
    {
        m_maxBuyCache.resize(prices.size());
        m_maxSellCache.resize(prices.size());
        
        return maxBuy(prices, 0);
    }
    
    int maxBuy(vector<int>& prices, int idxStart)
    {
        if(idxStart >= prices.size())
        {
            return 0;
        }
        
        if(m_maxBuyCache[idxStart])
        {
            return *m_maxBuyCache[idxStart];
        }
        
        int valMaxBuy = 0;
        for(int idx = idxStart; idx < prices.size(); idx++)
        {
            int newBuyValue = -prices[idx] + maxSell(prices, idx + 1);
            
            if(newBuyValue > valMaxBuy)
            {
                valMaxBuy = newBuyValue;
            }
        }
        
        m_maxBuyCache[idxStart] = valMaxBuy;
        return valMaxBuy;
    }
    
    int maxSell(vector<int>& prices, int idxStart)
    {
        if(idxStart >= prices.size())
        {
            return 0;
        }
        
        if(m_maxSellCache[idxStart])
        {
            return *m_maxSellCache[idxStart];
        }
        
        int valMaxSell = 0;
        for(int idx = idxStart; idx < prices.size(); idx++)
        {
            int newSellValue = prices[idx] + maxBuy(prices, idx + 2);
            
            if(newSellValue > valMaxSell)
            {
                valMaxSell = newSellValue;
            }
        }
        
        m_maxSellCache[idxStart] = valMaxSell;
        return valMaxSell;
    }
};
