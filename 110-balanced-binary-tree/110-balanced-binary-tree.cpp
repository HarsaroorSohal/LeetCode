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
    bool isB = true;
    int height(TreeNode* temp)
    {
        if(!isB)
            return -1;
        if(!temp)
            return 0;
        int l = height(temp->left);
        int r = height(temp->right);
        if(abs(l-r) > 1)
        {
            isB = false;
        }
        int h = max(l,r) + 1;
        return(h);
    }
    bool isBalanced(TreeNode* root) {
        int whatever = height(root);
        return(isB);
    }
};