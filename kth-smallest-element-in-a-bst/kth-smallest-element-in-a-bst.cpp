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
    int ans = -1;
    void inorder(TreeNode* root, int &k)
    {
        if(ans != -1)
            return;
        if(root-> left) inorder(root->left,k);
        // cout << root-> val << k << endl;
        k--;
        if(k == 0 && ans == -1)
        {
            ans = root->val;
        }
        if(root->right) inorder(root->right,k);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return(ans);
    }
};