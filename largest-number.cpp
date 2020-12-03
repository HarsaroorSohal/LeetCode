class Solution {
public:
    static bool comp(int &a , int &b)
    {
        string lr= to_string(a) + to_string(b);
        string rl= to_string(b) + to_string(a);
        return(lr > rl);
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),comp);
        string ans = "";
        for(int i : nums) 
        {
            ans = ans + to_string(i);
        }
        if(ans[0]=='0' && ans[ans.size()-1]=='0') return("0");
        return(ans);
    }
};
