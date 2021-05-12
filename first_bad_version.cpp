// https://leetcode.com/problems/first-bad-version/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int nLastGood = 1;
        int nFirstBad = n;
        
        while(nLastGood < nFirstBad)
        {
            int nMid = nLastGood + 0.5 * (nFirstBad - nLastGood);
            
            if(isBadVersion(nMid))
            {
                nFirstBad = nMid;
            }
            else
            {
                nLastGood = nMid + 1;
            }
        }

        return nFirstBad;
    }
};
