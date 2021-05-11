// https://leetcode.com/problems/climbing-stairs/

class Solution
{
private:
    std::vector<std::optional<int>> m_vSubproblems;
    
public:
    int climbStairs(int n)
    {
        m_vSubproblems.resize(n);
        
        return GetDistinct(0, n);
    }
    
    int GetDistinct(int nCur, const int& nTop)
    {
        if(nCur == nTop)
        {
            return 1;
        }
        
        if(m_vSubproblems[nCur])
        {
            return m_vSubproblems[nCur].value();
        }
        
        int nTotal = 0;
        
        if(nTop >= nCur + 1)
        {
            nTotal += GetDistinct(nCur + 1, nTop);
        }
        
        if(nTop >= nCur + 2)
        {
            nTotal += GetDistinct(nCur + 2, nTop);
        }
        
        m_vSubproblems[nCur] = nTotal;
        return nTotal;
    }
};
