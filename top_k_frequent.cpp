// https://leetcode.com/problems/top-k-frequent-elements/

class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        // count the number of occurences of each item
        std::unordered_map<int, int> counts;
        for(int const& n : nums)
        {
            counts[n] += 1;
        }
    
        // create the result vector from the keys since this ensures no duplicates
        vector<int> vRet;
        for(const auto& [key, value] : counts)
        {
            vRet.emplace_back(key);
        }
        
        // create the comparison function to sort the result array based on counts
        auto comp = [&counts](int a, int b) {
            return counts[a] > counts[b];
        };
        
        // sort the result array
        std::sort(vRet.begin(), vRet.end(), comp);
        
        // trim the result array
        vRet.resize(k);
        
        return vRet;
    }
};
