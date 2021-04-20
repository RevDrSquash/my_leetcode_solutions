// https://leetcode.com/problems/similar-string-groups/

class Solution
{
    bool AreSimilar(const string& s1, const string& s2)
    {
        int numDiffs = 0;
        for(int a = 0; a < s1.length(); a++)
        {
            if(s1[a] != s2[a])
            {
                numDiffs++;
                
                if(numDiffs >= 3)
                {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool BelongsInSet(const string& word, vector<const string*>& set)
    {
        for(const string* setWord : set)
        {
            if(AreSimilar(*setWord, word))
            {
                return true;
            }
        }
        
        return false;
    }
    
public:
    int numSimilarGroups(vector<string>& strs)
    {
        vector<vector<const string*>> sets;
        for(const string& newWord : strs)
        {
            vector<const string*>* pFirstSet = nullptr;
            for(auto it = sets.begin(); it != sets.end();)
            {
                if(BelongsInSet(newWord, *it))
                {
                    if(pFirstSet == nullptr)
                    {
                        pFirstSet = &(*it);
                        it++;
                    }
                    else
                    {
                        pFirstSet->insert(pFirstSet->end(), it->begin(), it->end());
                        sets.erase(it);
                    }
                }
                else
                {
                    it++;
                }
            }
            
            if(pFirstSet == nullptr)
            {
                sets.emplace_back();
                pFirstSet = &(sets.back());
            }
            
            pFirstSet->emplace_back(&newWord);
        }
        
        return sets.size();
    }
};
