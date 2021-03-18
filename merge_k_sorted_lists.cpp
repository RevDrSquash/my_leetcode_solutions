// https://leetcode.com/problems/merge-k-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
    vector<int> m_heap;
    
    void MinHeapify(int rootIndex)
    {
        int leftIndex = 1 + 2 * rootIndex;
        int rightIndex = 2 + 2 * rootIndex;
        int smallestIndex = rootIndex;
        
        if(leftIndex < m_heap.size() && m_heap[leftIndex] < m_heap[smallestIndex])
        {
            smallestIndex = leftIndex;
        }
        
        if(rightIndex < m_heap.size() && m_heap[rightIndex] < m_heap[smallestIndex])
        {
            smallestIndex = rightIndex;
        }
        
        if(smallestIndex != rootIndex)
        {
            swap(m_heap[smallestIndex], m_heap[rootIndex]);
            MinHeapify(smallestIndex);
        }
    }
    
    int PopMin()
    {
        int ret = m_heap[0];
        
        m_heap[0] = m_heap[m_heap.size() - 1];
        m_heap.pop_back();
        
        if(!m_heap.empty())
        {
            MinHeapify(0);
        }
        
        return ret;
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        ListNode* pAnswerHead = nullptr;
        ListNode* pPrevNode = nullptr;
        
        for(ListNode*& pNode : lists)
        {
            while(pNode != nullptr)
            {
                if(pAnswerHead == nullptr)
                {
                    pAnswerHead = pNode;
                }
                else
                {
                    pPrevNode->next = pNode;
                }
                
                pPrevNode = pNode;
                
                m_heap.push_back(pNode->val);
                pNode = pNode->next;
            }
        }
        
        if(pAnswerHead == nullptr)
            return nullptr;
        
        if(m_heap.empty())
            return nullptr;
        
        for(int index = floor(0.5 * (m_heap.size() - 1)); index >= 0; index--)
        {
            MinHeapify(index);
        }
        
        ListNode* pAnswerNode = pAnswerHead;
        while(pAnswerNode != nullptr)
        {
            pAnswerNode->val = PopMin();
            pAnswerNode = pAnswerNode->next;
        }
        
        return pAnswerHead;
    }
};
