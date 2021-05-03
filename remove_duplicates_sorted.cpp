// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        if(nums.empty())
        {
            return 0;
        }
        
        vector<int>::iterator itReplace = nums.begin();
        
        for(vector<int>::const_iterator itCheck = nums.begin() + 1; itCheck != nums.end(); itCheck++)
        {
            if(*itCheck != *itReplace)
            {
                itReplace++;
                *itReplace = *itCheck;
            }
        }
        
        return itReplace - nums.begin() + 1;
    }
};
