// https://leetcode.com/problems/implement-trie-prefix-tree/

class Trie
{
    class TrieNode
    {
    public:
        TrieNode()
        {
            m_keys.fill(nullptr);
        }
        
        ~TrieNode()
        {
            for(TrieNode*& pNode : m_keys)
            {
                if(pNode != nullptr)
                {
                    delete pNode;
                    pNode = nullptr;
                }
            }
        }
        
        TrieNode* GetChild(char c)
        {
            return m_keys[c - 'a'];
        }
        
        void AddChild(char c, TrieNode* pNode)
        {
            m_keys[c - 'a'] = pNode;
        }
        
        void SetEnd(bool bEnd)
        {
            m_bEnd = bEnd;
        }
        
        bool GetEnd()
        {
            return m_bEnd;
        }
        
    private:
        array<TrieNode*, 26> m_keys;
        bool m_bEnd = false;
    };
    
public:
    /** Initialize your data structure here. */
    Trie()
    {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode* pNode = &m_head;
        for(const char& c : word)
        {
            TrieNode* pChild = pNode->GetChild(c);
            if(pChild == nullptr)
            {
                pChild = new TrieNode();
                pNode->AddChild(c, pChild);
            }
            
            pNode = pChild;
        }
        
        pNode->SetEnd(true);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode* pNode = &m_head;
        for(const char& c : word)
        {
            TrieNode* pChild = pNode->GetChild(c);
            if(pChild == nullptr)
            {
                return false;
            }
            
            pNode = pChild;
        }
        
        return pNode->GetEnd();
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode* pNode = &m_head;
        for(const char& c : prefix)
        {
            TrieNode* pChild = pNode->GetChild(c);
            if(pChild == nullptr)
            {
                return false;
            }
            
            pNode = pChild;
        }
        
        return true;
    }
    
private:
    TrieNode m_head;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
