class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        map<int,int> store;
        int mx = 1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i] > nums[j])
                {
                    dp[i] = max(dp[i],dp[j] + 1);
                    mx = max(dp[i],mx);
                }
            }
        }
        /*cout << mx << endl;
        return(count);*/
        return(mx);
    }
};
