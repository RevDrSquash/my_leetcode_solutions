// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int maxLength = 0;
        int curLength = 0;
        
        int back = 0;
        
        std::unordered_set<char> characters;
        for(int a = 0; a < s.length(); a++)
        {
            while(characters.count(s[a]) > 0)
            {
                characters.erase(s[back]);
                back++;
            }
            
            characters.insert(s[a]);
            
            curLength = characters.size();
            maxLength = std::max(maxLength, curLength);
        }
        
        return maxLength;
    }
};
