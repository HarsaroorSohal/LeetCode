class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //dp[n][m] -> lcs of text1(0-n) and text2(0-m)
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1[i-1] == text2[j-1])
                {
                    dp[i][j] = max(dp[i][j],dp[i-1][j-1] + 1);
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
        // for(int i=0;i<=n;i++)
        // {
        //     for(int j=0;j<=m;j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return(dp[n][m]);
        
    }
};