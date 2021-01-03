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
    const int mod = 1e5 + 7;
    int help(TreeNode* root, map<pair<TreeNode*,bool>,int> &dp, bool taken, int& ans)
    {
        if(root==NULL) return(0);
        if(dp.count({root,taken})) return dp[{root,taken}];
        //case 1 -> if taken is false, then take
        int val1 = -1;
        if(taken==false)
        {
            val1 = root->val + help(root->left,dp,true,ans) + help(root->right,dp,true,ans);;
        }
        //case 2 -> skip this node
        int val2 = -1;
        val2 = help(root->left,dp,false,ans) + help(root->right,dp,false,ans);
        ans = max({val1,val2});
        dp[{root,taken}] = ans;
        return(ans);
    }
    int rob(TreeNode* root) {
        if(root==NULL) return(0);
        map<pair<TreeNode*, bool>,int> dp;
        int ans = 0;
        int temp = help(root,dp,false,ans);
        /*for(int i=0;i<dp.size();i++)
        {
            dp[]
        }*/
        return(ans);
    }
};
