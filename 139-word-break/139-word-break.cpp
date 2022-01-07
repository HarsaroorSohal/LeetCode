class Solution {
public:
    unordered_set<string> store;
    bool valid(string s)
    {
        return(store.find(s)!=store.end());
    }
    bool wordBreak(string s, vector<string>& v) {
        if(v.size()==0) return(false);
        store.clear();
        int n = s.size();
        for(int i=0;i<v.size();i++) store.insert(v[i]);
        vector<bool> dp(s.size(),false);
         dp[0] = true;
        for(int i=1;i<=s.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(dp[j] && valid(s.substr(j,i-j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return(dp[s.size()]);
    }
    
};