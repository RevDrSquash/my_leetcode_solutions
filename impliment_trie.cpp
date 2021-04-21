// https://leetcode.com/problems/implement-trie-prefix-tree/

class Trie
{
    class TrieNode
    {
    public:
        TrieNode()
        {
            
        }
        
        void Insert(const string& word, string::const_iterator it)
        {
            if(it == word.end())
            {
                m_words.emplace(word);
            }
            else
            {
                if(m_children.count(*it) < 1)
                {
                    m_children[*it] = make_shared<TrieNode>();
                }
                
                m_children[*it]->Insert(word, it+1);
            }
        }
        
        bool HasWord(const string& word)
        {
            return m_words.count(word) > 0;
        }
        
        shared_ptr<TrieNode> FindNode(const string& word, string::const_iterator it)
        {
            if(m_children.count(*it) > 0)
            {
                string::const_iterator itNext = it+1;
                if(itNext == word.end())
                {
                    return m_children[*it];
                }
                else
                {
                    return m_children[*it]->FindNode(word, itNext);
                }
            }
            else
            {
                return nullptr;
            }
        }
        
    private:
        unordered_map<char, shared_ptr<TrieNode>> m_children;
        set<string> m_words;
    };
    
public:
    /** Initialize your data structure here. */
    Trie()
    {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word)
    {
        m_head.Insert(word, word.begin());
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        shared_ptr<TrieNode> pNode = m_head.FindNode(word, word.begin());
        if(pNode != nullptr)
        {
            return pNode->HasWord(word);
        }
        else
        {
            return false;
        }
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        shared_ptr<TrieNode> pNode = m_head.FindNode(prefix, prefix.begin());
        return pNode != nullptr;
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
