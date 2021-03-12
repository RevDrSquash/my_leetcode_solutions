// https://leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x)
    {
        const int maxPreShift = std::numeric_limits<int>::max() / 10;
        const int maxLastDigit = std::numeric_limits<int>::max() % 10;
        
        const int minPreShift = std::numeric_limits<int>::min() / 10;
        const int minLastDigit = std::numeric_limits<int>::min() % 10;
        
        int reversed = 0;
        while (x != 0)
        {
            int digit = x % 10;
            
            if(reversed > maxPreShift) return 0;
            if(reversed == maxPreShift && digit > maxLastDigit) return 0;
            
            if(reversed < minPreShift) return 0;
            if(reversed == minPreShift && digit < minLastDigit) return 0;
                
            reversed = reversed * 10 + digit;

            x = x / 10;
        }
        
        return reversed;
    }
};
