class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++) dp[i][i] = true;
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1]) dp[i-1][i] = true;
        }
        string ans;
        int sze = 0;
        for(int i=3;i<=n;i++)
        {
            for(int j=0;j<=n-i;j++)
            {
                int left = j;
                int right = j+i-1;
                if(s[left]==s[right] && dp[left+1][right-1])
                {
                    dp[left][right] = true;
                   
                }
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=n-i;j++)
            {
                int left = j;
                int right = j+i-1;
                if(dp[left][right])
                {
                    if(right-left+1 > sze)
                    {
                        ans = s.substr(left,right-left+1);
                        sze = right-left+1;
                    }
                }
            }
        }
        return(ans);
    }
};