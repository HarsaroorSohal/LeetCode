class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            auto ele = m.find(target-nums[i]);
            if(ele != m.end())
            {
                ans.push_back(i);
                ans.push_back(ele->second);
            }
            m.insert(make_pair(nums[i],i));
        }
        return(ans);
    }
};