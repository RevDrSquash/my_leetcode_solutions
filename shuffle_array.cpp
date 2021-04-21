// https://leetcode.com/problems/shuffle-an-array/

class Solution
{
private:
    vector<int> m_original;
    
public:
    Solution(vector<int>& nums)
    {
        m_original = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return m_original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        vector<int> vRet = m_original;
        
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine generator(seed);
        
        for(int idx = 0; idx < vRet.size(); idx++)
        {
            std::uniform_int_distribution<int> distribution(idx,vRet.size()-1);
            int swapIndex = distribution(generator);
            swap(vRet[idx], vRet[swapIndex]);
        }
        
        //std::shuffle(vRet.begin(), vRet.end(), std::default_random_engine(seed));
        
        return vRet;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
