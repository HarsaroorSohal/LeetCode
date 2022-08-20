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
class Solution {
public:
    bool helper(TreeNode* root, int target, int current)
    {
        if(!root)
            return false;
        if(root->val+current == target && !root->left && !root->right)
            return(true);
        return(helper(root->left, target, current+ root->val) || helper(root->right, target, current+root->val));
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return(helper(root, targetSum, 0));
    }
};