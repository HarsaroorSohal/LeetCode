class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int min_yet = prices[0];
        for(int i=1;i<n;i++)
        {
            ans = max(ans,prices[i] - min_yet);
            min_yet = min(min_yet,prices[i]);
        }
        return(ans);
    }
};