// https://leetcode.com/problems/product-of-array-except-self/

class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> answer(nums.size(), 0);
        
        int zeroPos = -1;
        int product = 1;
        for(int idx = 0; idx < nums.size(); idx++)
        {
            if(nums[idx] == 0)
            {
                if(zeroPos >= 0)
                {
                    // second 0 means everything is 0's
                    return answer;
                }
                else
                {
                    zeroPos = idx;
                }
                continue;
            }
            
            product *= nums[idx];
        }
        
        if(zeroPos >= 0)
        {
            // Minor optimization since if there's a zero we only need to fill in that one item.
            answer[zeroPos] = product;
            return answer;
        }
        
        for(int idx = 0; idx < nums.size(); idx++)
        {
            // Description suggests there's a way to do this without the division but I can't see it.
            answer[idx] = product / nums[idx];
        }
        
        return answer;
    }
};
