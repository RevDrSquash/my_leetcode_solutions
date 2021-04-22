// https://leetcode.com/problems/robot-bounded-in-circle/

class Solution
{
public:
    bool isRobotBounded(string instructions)
    {
        int X = 0;
        int Y = 0;
        
        int direction = 0;
        for(const char& c : instructions)
        {
            if(c == 'R')
            {
                direction = (direction + 1 + 4) % 4;
            }
            else if(c == 'L')
            {
                direction = (direction - 1 + 4) % 4;
            }
            else if(c == 'G')
            {
                switch (direction)
                {
                    case 0:
                        Y--;
                        break;
                    case 1:
                        X++;
                        break;
                    case 2:
                        Y++;
                        break;
                    case 3:
                        X--;
                        break;
                }
            }
        }
        
        if(X == 0 && Y == 0)
        {
            return true;
        }
        else
        {
            if(direction != 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};
