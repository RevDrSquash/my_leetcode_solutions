// https://leetcode.com/problems/sliding-window-maximum/

class Solution
{
    deque<int> maxValueIdxTracker;
    
    void AddToWindow(const vector<int>& nums, int index)
    {
        if(maxValueIdxTracker.empty())
        {
            maxValueIdxTracker.push_front(index);
        }
        else
        {
            while(!maxValueIdxTracker.empty() && nums[maxValueIdxTracker.front()] < nums[index])
            {
                maxValueIdxTracker.pop_front();
            }
            
            maxValueIdxTracker.push_front(index);
        }
    }
    
    void RemoveFromWindow(int index)
    {
        if(index >= maxValueIdxTracker.back())
        {
            maxValueIdxTracker.pop_back();
        }
    }
    
    int GetMaxInWindow(const vector<int>& nums)
    {
        return nums[maxValueIdxTracker.back()];
    }
    
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        for(int idx = 0; idx < (k - 1); idx++)
        {
            AddToWindow(nums, idx);
        }
        
        vector<int> answer(nums.size() - k + 1);
        
        for(int idx = (k - 1), idxStart = 0; idx < nums.size(); idx++, idxStart++)
        {
            AddToWindow(nums, idx);
            
            answer[idxStart] = GetMaxInWindow(nums);
            
            RemoveFromWindow(idxStart);
        }
        
        return answer;
    }
};
