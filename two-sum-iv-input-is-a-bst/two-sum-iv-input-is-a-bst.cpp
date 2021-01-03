/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        for(auto i = root; i!=NULL;i = i->left)
            st1.push(i);
        for(auto i = root; i!=NULL;i = i->right)
            st2.push(i);
        while(!st1.empty() && !st2.empty() && st1.top() != st2.top())
        {
            int sum = st1.top()->val + st2.top()->val;
            if(sum == k)
                return(true);
            if(sum < k)
            {
                auto i = st1.top();
                st1.pop();
                i = i->right;
                for(; i!=NULL;i = i->left)
                    st1.push(i);
            }
            else
            {
                auto i = st2.top();
                st2.pop();
                i = i->left;
                for(; i!=NULL; i = i->right)
                    st2.push(i);
            }
        }
        return(false);
    }
};
