class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int m = B.size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int ans = 0;
        int ansi, ansj;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(A[i]==B[j])
                {
                    if(i&&j) dp[i][j] = max(dp[i][j],dp[i-1][j-1] + 1);
                    else dp[i][j] = 1;
                    if(dp[i][j] > ans)
                    {
                        ans = dp[i][j];
                        ansi = i;
                    }
                }
                /*else
                {
                    if(i&&j) dp[i][j] = max(dp[i][j],dp[i-1][j-1]);
                    else dp[i][j] = 0;
                }*/
            }
        }
        vector<int> temp;
        int count = ans;
        while(count--)
        {
            temp.push_back(A[ansi]);
            ansi--;
        }
        for(int i : temp) cout << i << " ";
        return(ans);
    }
};
