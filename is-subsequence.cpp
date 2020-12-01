class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        //dp[i][j] -> prefix till i of s is sub. of pref. till j of t;
        dp[0][0] = true;
        for(int i=1;i<=m;i++) dp[0][i] = true;
        for(int i=1;i<=n;i++) dp[i][0] = false;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(dp[i][j]==true) continue;
                if(s[i-1]==t[j-1])
                {
                    if(dp[i-1][j-1]==true)
                    {
                        dp[i][j] = true;
                    }
                }
                else
                {
                    if(dp[i][j-1]) dp[i][j] = true;
                }
            }
        }
        return(dp[n][m]);
    }
};
