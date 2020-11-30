class Solution {
public:
    bool isSquare(int a)
    {
        int temp = (int)sqrt(a);
        return(a == (temp*temp));
    }
    int numSquares(int n) {
        const int inf = 1e9 + 7;
        vector<int> dp(n+1,inf);
        dp[0] = 0;
        dp[1] = 1;
        //if(isSquare(4)) cout << "ass";
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j*j<=i;j++)
            {
                dp[i] = min(dp[i],dp[i-(j*j)] + 1);
            }
        }
        return(dp[n]);
    }
};
