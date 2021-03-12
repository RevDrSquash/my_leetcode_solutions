// https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/589/week-2-march-8th-march-14th/3668/

class Solution {
public:
    unordered_map<int, int> mapResultCache;
    
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
        {
            return 0;
        }
        
        int result = -1;
        
        for(int coin : coins)
        {
            if(amount < coin)
            {
                continue;
            }
            else
            {
                int newAmount = amount - coin;
                unordered_map<int, int>::iterator it = mapResultCache.find(newAmount);
                
                int remainingCoins = -1;
                if(it != mapResultCache.end())
                {
                    remainingCoins = it->second;
                }
                else
                {
                    remainingCoins = coinChange(coins, newAmount);
                    mapResultCache[newAmount] = remainingCoins;
                }
                
                if(remainingCoins >= 0)
                {
                    remainingCoins += 1;
                    if(remainingCoins < result || result < 0)
                    {
                        result = remainingCoins;
                    }
                }
            }
        }
        
        return result;
    }
	
};
