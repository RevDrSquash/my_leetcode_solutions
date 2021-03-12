// https://leetcode.com/problems/unique-paths-iii/

class Solution {
    struct Point {
        int X;
        int Y;
    };
    
public:
    Point start = {0,0};
    int targetLength = 0;
    
    int uniquePathsIII(vector<vector<int>>& grid)
    {
        for(int X = 0; X < grid.size(); X++)
        {
            for(int Y = 0; Y < grid[0].size(); Y++)
            {
                if(grid[X][Y] == 1)
                {
                    start = {X, Y};
                }
                
                if(grid[X][Y] >= 0)
                {
                    targetLength++;
                }
            }
        }
        
        return countPaths(grid, 1, start);
    }
    
    int countPaths(vector<vector<int>>& grid, int length, const Point& point)
    {
        if(point.X < 0 || point.X >= grid.size() || point.Y < 0 || point.Y >= grid[0].size())
        {
            return 0;
        }
        
        if(grid[point.X][point.Y] == 2)
        {
            if(length == targetLength)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if(grid[point.X][point.Y] < 0)
        {
            return 0;
        }
        else
        {
            int count = 0;
            
            int old = grid[point.X][point.Y];
            grid[point.X][point.Y] = -1;
            
            count += countPaths(grid, length + 1, {point.X - 1, point.Y});
            
            count += countPaths(grid, length + 1, {point.X + 1, point.Y});
            
            count += countPaths(grid, length + 1, {point.X, point.Y - 1});
                
            count += countPaths(grid, length + 1, {point.X, point.Y + 1});
                
            grid[point.X][point.Y] = old;
            
            return count;
        }
        
        return 0;
    }
};
