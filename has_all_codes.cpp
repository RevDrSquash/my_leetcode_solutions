// https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/589/week-2-march-8th-march-14th/3669/

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> setSubstrings(pow(2,k));
        
        const int stringLength = s.length();
        for(int pos = 0; pos <= (stringLength - k); pos++)
        {
            setSubstrings.insert(s.substr(pos, k));
        }
        
        return setSubstrings.size() == pow(2,k);
    }
};
