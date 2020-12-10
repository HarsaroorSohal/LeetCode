class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int inf = (1e9 + 7) * (-1);
        int ans = arr[0];
        vector<vector<int>> dp(n+1,vector<int>(2,inf));
        //[0] without del, [1] with del.
        for(int i=0;i<n;i++)
        {
            dp[i+1][0] = max((dp[i][0] + arr[i]), arr[i]);
            dp[i+1][1] = max((dp[i][1] + arr[i]), arr[i]);
            dp[i+1][1] = max(dp[i][0],dp[i+1][1]);
            ans = max({ans,dp[i+1][0],dp[i+1][1]});
        }
        return(ans);
    }
};
