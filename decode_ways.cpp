// https://leetcode.com/problems/decode-ways/

class Solution
{
public:
    int numDecodings(string s)
    {
        vector<optional<int>> data(s.size());
        
        return findDecodings(s, data, 0);
    }
    
    int findDecodings(const string& s, vector<optional<int>>& data, int index)
    {
        if(index >= s.size())
        {
            return 0;
        }
        
        if(data[index])
        {
            return *data[index];
        }
        
        if(s[index] < '1')
        {
            // no valid characters
            return 0;
        }

        int count = 0;
        if(s[index] <= '9')
        {
            // valid single digit character
            
            if((index + 1) < s.size())
            {
                int nextDecodings = findDecodings(s, data, index + 1);
                if(nextDecodings > 0)
                    count += nextDecodings;
            }
            else
            {
                count++;
            }
        }
        
        if((s[index] == '1' && s[index + 1] >= '0' && s[index + 1] <= '9') ||
           (s[index] == '2' && s[index + 1] >= '0' && s[index + 1] <= '6'))
        {
            // valid double digit character
            
            if((index + 2) < s.size())
            {
                int nextDecodings = findDecodings(s, data, index + 2);
                if(nextDecodings > 0)
                    count += nextDecodings;
            }
            else
            {
                count++;
            }
        }
        
        data[index] = count;
        return count;
    }
};
