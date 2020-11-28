class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        //same as finding the max square maybe
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp;
        int ans = 0;
        dp = matrix;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j])
                    dp[i][j] = max(dp[i][j], min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]}) + 1);
                if(dp[i][j] > 1) 
                {
                    cout << i << " " << j << endl;
                    ans+=dp[i][j]-1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j] == 1) ans++;
            }
        }
        return(ans);
    }
};
