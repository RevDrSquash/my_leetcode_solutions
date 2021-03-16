// https://leetcode.com/problems/reducing-dishes/

class Solution {
    static bool decendingSort (int i,int j) { return (i>j); }
    
public:
    int maxSatisfaction(vector<int>& satisfaction)
    {
        // sort satisfaction by decending value
        std::sort(satisfaction.begin(), satisfaction.end(), decendingSort);
        
        int coefficient = 0;
        int curSum = 0;
        for(const int& score : satisfaction)
        {
            int newSum = curSum + score;
            if(newSum > 0)
            {
                curSum = newSum;
                coefficient += newSum;
            }
        }
        
        return coefficient;
    }
};
