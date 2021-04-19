// https://leetcode.com/problems/word-search-ii/

class Solution
{
    class TrieNode
    {
    public:
        TrieNode(char c) : m_Char(c)
        {
            
        }
        
        char GetChar() const { return m_Char; };
        
        bool AddWord(const string* pString, std::string::const_iterator it)
        {
            if(it == pString->end())
            {
                m_vWords.push_back(pString);
                return true;
            }
            
            TrieNode* pChild = GetChild(*it);
            if(nullptr == pChild)
            {
                std::shared_ptr<TrieNode> pNewChild = std::make_shared<TrieNode>(*it);
                pNewChild->AddWord(pString, it+1);
                
                m_children[*it] = pNewChild;
            }
            else
            {
                pChild->AddWord(pString, it+1);
            }
            
            return true;
        }
        
        TrieNode* GetChild(char c)
        {
            if(m_children.count(c) <= 0)
            {
                return nullptr;
            }
            
            return m_children[c].get();
            
            return nullptr;
        }
        
        void GetWords(unordered_set<string>& words)
        {
            for(const string* pMyWord : m_vWords)
            {
                words.emplace(*pMyWord);
            }
        }
        
        bool RemoveWord(const string* pString, std::string::const_iterator it)
        {
            if(it == pString->end())
            {
                for(int idx = 0; idx < m_vWords.size(); idx++)
                {
                    if(*m_vWords[idx] == *pString)
                    {
                        m_vWords.erase(m_vWords.begin() + idx);
                        break;
                    }
                }
            }
            else
            {
                TrieNode* pChild = GetChild(*it);
                if(pChild == nullptr)
                {
                    return false;
                }
                else
                {
                    if(pChild->RemoveWord(pString, it+1))
                    {
                        m_children.erase(*it);
                    }
                }
            }
            
            return m_vWords.empty() && m_children.empty();
        }
        
        void GetAllWords(vector<string>& words)
        {
            for(const string* pMyWord : m_vWords)
            {
                words.emplace_back(*pMyWord);
            }
            
            for(auto [c, pChild] : m_children)
            {
                pChild->GetAllWords(words);
            }
        }
        
        string Print()
        {
            string strOut("[");
            strOut.append(1, m_Char);
            
            for(auto [c, pChild] : m_children)
            {
                strOut.append(pChild->Print());
            }
            
            strOut.append("]");
            
            return strOut;
        }
        
    private:
        char m_Char;
        std::vector<const string*> m_vWords;
        std::unordered_map<char, std::shared_ptr<TrieNode>> m_children;
    };
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        TrieNode head(' ');
        
        for(std::string& word : words)
        {
            head.AddWord(&word, word.begin());
        }
        
        unordered_set<string> foundWords;
        
        
        for(int X = 0; X < board.size(); X++)
        {
            for(int Y = 0; Y < board[X].size(); Y++)
            {
                unordered_set<string> newFoundWords;
                
                CheckCell(X, Y, &head, newFoundWords, board);
                
                for(const string& newWord : newFoundWords)
                {
                    head.RemoveWord(&newWord, newWord.begin());
                    foundWords.emplace(newWord);
                }
            }
        }
        
        /*
        vector<string> vRet;
        vRet.push_back(head.Print());
        
        string test("aa");
        head.RemoveWord(&test, test.begin());
        vRet.push_back(head.Print());
        */
        
        //head.GetAllWords(vRet);]
        
        vector<string> vRet(foundWords.begin(), foundWords.end());
        return vRet;
    }
    
    void CheckCell(int X, int Y, TrieNode* pNode, unordered_set<string>& foundWords, vector<vector<char>>& board)
    {
        TrieNode* pChild = pNode->GetChild(board[X][Y]);
        if(nullptr == pChild)
        {
            return;
        }
        
        pChild->GetWords(foundWords);
        
        char cSaved = board[X][Y];
        board[X][Y] = 'X';
        
        if(X >= 1)
        {
            CheckCell(X-1, Y, pChild, foundWords, board);
        }
        
        if(Y >= 1)
        {
            CheckCell(X, Y-1, pChild, foundWords, board);
        }
        
        if((X+1) < board.size())
        {
            CheckCell(X+1, Y, pChild, foundWords, board);
        }
        
        if((Y+1) < board[X].size())
        {
            CheckCell(X, Y+1, pChild, foundWords, board);
        }
        
        board[X][Y] = cSaved;
    }
};
