// https://leetcode.com/problems/trapping-rain-water/

class Solution
{
public:
    int trap(vector<int>& height)
    {
        std::stack<std::pair<int,int>> scan;
        
        int water = 0;
        for(int idx = 0; idx < height.size(); idx++)
        {
            if(height[idx] == 0)
                continue;
            
            int waterLevel = 0;
            while(!scan.empty() && height[idx] > waterLevel)
            {
                int nLevel = min(height[idx], scan.top().first);
                water += max(nLevel - waterLevel, 0) * (idx - scan.top().second - 1);
                waterLevel = nLevel;
                
                if(height[idx] > scan.top().first)
                    scan.pop();
            }
            
            scan.push({ height[idx], idx });
        }
        
        return water;
    }
};
