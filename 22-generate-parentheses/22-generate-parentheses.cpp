class Solution {
public:
    void rec(string paran, int open, int n, vector<string> &ans)
    {
        if(paran.length() == 2*n)
        {
            if(open == 0) ans.push_back(paran);
            return;
        }
        if(open)
        {
            rec(paran + ')', open-1, n, ans);
        }
        rec(paran + '(', open+1 , n, ans);
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string paran = "";
        rec(paran,0,n,ans);
        return(ans);
        
    }
};