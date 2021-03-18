// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == nullptr)
        {
            return nullptr;
        }
        
        if(root == p)
        {
            return root;
        }
        else if(root == q)
        {
            return root;
        }
        
        TreeNode* pResLeft = root->left != nullptr ? lowestCommonAncestor(root->left, p, q) : nullptr;
        TreeNode* pResRight = root->right != nullptr ? lowestCommonAncestor(root->right, p, q) : nullptr;
        
        if(pResLeft != nullptr && pResRight != nullptr)
        {
            return root;
        }
        
        if(pResLeft != nullptr)
        {
            return pResLeft;
        }
        
        if(pResRight != nullptr)
        {
            return pResRight;
        }
        
        return nullptr;
    }
};
