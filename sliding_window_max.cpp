// https://leetcode.com/problems/sliding-window-maximum/

// to slow at the moment

class Solution
{
    unordered_map<int, int> mapDistinctNums;
    int windowMax = numeric_limits<int>::min();
    
    void addToWindow(int num)
    {
        mapDistinctNums[num] += 1;
            
        if(num > windowMax)
        {
            windowMax = num;
        }
    }
    
    void removeFromWindow(int num)
    {
        mapDistinctNums[num] -= 1;

        if(mapDistinctNums[num] <= 0)
        {
            mapDistinctNums.erase(num);

            // removed the old max so find the new max
            if(num == windowMax)
            {
                unordered_map<int, int>::iterator itMax = max_element(mapDistinctNums.begin(), mapDistinctNums.end());
                if(itMax != mapDistinctNums.end())
                {
                    windowMax = itMax->first;
                }
                else
                {
                    windowMax = numeric_limits<int>::min();
                }
            }
        }
    }
    
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        mapDistinctNums.reserve(k+1);
        
        for(int idx = 0; idx < (k - 1); idx++)
        {
            addToWindow(nums[idx]);
        }
        
        vector<int> answer(nums.size() - k + 1);
        
        for(int idx = (k - 1), idxStart = 0; idx < nums.size(); idx++, idxStart++)
        {
            addToWindow(nums[idx]);
            
            answer[idxStart] = windowMax;
            
            removeFromWindow(nums[idxStart]);
        }
        
        return answer;
    }
};
