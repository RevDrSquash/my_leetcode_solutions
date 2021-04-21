// https://leetcode.com/problems/reverse-string/

class Solution
{
public:
    void reverseString(vector<char>& s)
    {
        vector<char>::iterator itFront = s.begin();
        vector<char>::iterator itBack = s.end()-1;
        while(itFront < itBack)
        {
            char temp = *itFront;
            *itFront = *itBack;
            *itBack = temp;
            
            itFront++;
            itBack--;
        }
    }
};
