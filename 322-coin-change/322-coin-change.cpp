class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int maxNum = pow(2,31) - 1;
        vector<int> dp(amount+1,maxNum);
        dp[0] = 0;
        for(int coin : coins)
        {
            for(int i=0;i<=amount-coin;i++)
            {
                if(dp[i] != maxNum)
                    dp[i+coin] = min(dp[i+coin],dp[i]+1);
            }
        }
        for(int i=0;i<=amount; i++)
            cout << dp[i];
        if(dp[amount] == maxNum)
            return(-1);
        return(dp[amount]);
    }
};