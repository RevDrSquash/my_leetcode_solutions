// https://leetcode.com/problems/binary-trees-with-factors/

class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> subtrees;
    unordered_map<int, int> subtreeCount;
    
    int numFactoredBinaryTrees(vector<int>& arr)
    {
        subtrees = unordered_map<int, vector<pair<int, int>>>(arr.size());
        subtreeCount = unordered_map<int, int>(arr.size());
        
        for(const int& num : arr)
        {
            subtrees[num] = vector<pair<int, int>>();
        }
        
        for(const int& num : arr)
        {
            for(const int& factor : arr)
            {
                if(num % factor != 0)
                {
                    continue;
                }
                
                int otherFactor = num / factor;
                
                if(otherFactor != factor)
                {
                    if(subtrees.count(otherFactor) <= 0)
                    {
                        continue;
                    }
                }
                
                subtrees[num].push_back(pair<int, int>(factor, otherFactor));
            }
        }
        
        int count = 0;
        for(const int& num : arr)
        {
            count += 1;
            
            if(subtreeCount.count(num) > 0)
            {
                count += subtreeCount[num];
            }
            else
            {
                count += countTrees(num);
            }
            
            count = count % (1000000007);
        }
        
        return count % (1000000007);
    }
    
    int countTrees(int num)
    {
        if(subtreeCount.count(num) > 0)
        {
            return subtreeCount[num];
        }
        
        int count = 0;
        
        for(const auto& [factorA, factorB] : subtrees[num])
        {
            unsigned long long numSubtrees = 
                static_cast<unsigned long long>(1 + countTrees(factorA)) * 
                static_cast<unsigned long long>(1 + countTrees(factorB));
            count += static_cast<int>(numSubtrees % (1000000007));
            
            count = count % (1000000007);
        }
        
        subtreeCount[num] = count % (1000000007);
        return subtreeCount[num];
    }
};
