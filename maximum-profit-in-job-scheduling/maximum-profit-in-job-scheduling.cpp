class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        int n = startTime.size();
        for(int i=0;i<n;i++)
        {
            vector<int> temp =  {endTime[i], startTime[i], profit[i]};
            jobs.push_back(temp);
        }
        sort(jobs.begin(),jobs.end());
        map<int,int> dp; // {endTime, profit}
        dp[0] = 0;
        for(auto job : jobs)
        {
            //skip or try to take
            int start = job[1];
            int end = job[0];
            int profit = job[2];
            auto prev = dp.upper_bound(start);
            prev--;
            int maxProfitYet = prev->second;
            dp[end] = max(dp.rbegin()->second,maxProfitYet + profit);
        }
        return(dp.rbegin()->second);
    }
};
