// https://leetcode.com/problems/delete-node-in-a-linked-list/

class Solution
{
public:
    void deleteNode(ListNode* pNode)
    {
        if(nullptr == pNode || nullptr == pNode->next)
        {
            return;
        }
        
        ListNode* pTemp = pNode->next;
        
        pNode->val = pNode->next->val;
        pNode->next = pNode->next->next;
        
        delete pTemp;
    }
};
