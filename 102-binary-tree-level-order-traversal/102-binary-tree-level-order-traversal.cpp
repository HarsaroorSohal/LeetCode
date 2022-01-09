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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q, next;
        vector<vector<int>> ans;
        if(!root) return(ans);
        q.push(root);
        vector<int> curr_level;
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            curr_level.push_back(curr->val);
            if(curr->left)
            {
                next.push(curr->left);
            }
            if(curr->right)
            {
                next.push(curr->right);
            }
            if(q.empty())
            {
                if(!curr_level.empty())
                {
                    ans.push_back(curr_level);
                }
                curr_level.clear();
                swap(q,next);
            }
        }
        return(ans);
    }
};