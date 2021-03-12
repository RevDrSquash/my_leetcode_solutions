// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/

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
