// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
private:
    TreeNode* makeNode(int start, int end, vector<int> const& nums)
    {
        int mid = start + 0.5 * (end - start);
        TreeNode* node = new TreeNode(nums[mid]);
        
        if(mid > start)
        {
            node->left = makeNode(start, mid-1, nums);
        }
        
        if(mid < end)
        {
            node->right = makeNode(mid+1, end, nums);
        }
        
        return node;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return makeNode(0, nums.size() - 1, nums);
    }
};
