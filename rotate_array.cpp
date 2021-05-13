// https://leetcode.com/problems/rotate-array/

class Solution
{
public:
    // memory complexity: O(1)
    void rotate(vector<int>& nums, int k)
    {
        k = k % nums.size();
        
        int count = 0;
        int endCount = nums.size();
        
        int startIdx = 0;
        
        while(count < endCount)
        {
            int curIdx = startIdx;
            int temp = nums[curIdx];
            
            curIdx = (curIdx + k) % nums.size();
            
            do
            {
                std::swap(temp, nums[curIdx]);
                count++;
                
                curIdx = (curIdx + k) % nums.size();
            } while(curIdx != (startIdx + k) % nums.size() && count < endCount);
            
            startIdx++;
        }
    }
    
    // memory complexity: O(n)
    // void rotate(vector<int>& nums, int k)
    // {
    //     vector<int> newNums(nums.size());
    //     for(int n = 0; n < nums.size(); n++)
    //     {
    //         newNums[(n + k) % nums.size()] = nums[n];
    //     }
    //     
    //     nums = newNums;
    // }
};
