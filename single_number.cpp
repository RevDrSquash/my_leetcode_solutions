// https://leetcode.com/problems/single-number/

class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        int res = 0;
        for(int const& n : nums)
        {
            res ^= n;
        }
        
        return res;
    }
};
