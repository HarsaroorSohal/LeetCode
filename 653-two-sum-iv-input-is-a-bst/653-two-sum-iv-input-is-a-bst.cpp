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
    unordered_set<int> s;
    bool found = false;
    void helper(TreeNode* root, int k)
    {
        if(root == NULL)
            return;
        if(s.count(k-(root->val)))
        {
            found = true;
            return;
        }
        s.insert(root->val);
        helper(root->left,k);
        helper(root->right,k);
            
    }
    bool findTarget(TreeNode* root, int k) {
        helper(root,k);
        return found;
        
    }
};