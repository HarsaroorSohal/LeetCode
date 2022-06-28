
class Solution {
    
public:
    static bool comp(const pair<char,int> &a, const pair<char,int> &b)
    {
        return(a.second < b.second);
    }
    int minDeletions(string s) {
        int n = s.size();
        unordered_set<int> store;
        map<char,int> m;
        for(char i : s)
        {
            m[i]++;
        }
        vector<pair<char, int>> vec;
        for (auto j : m) 
        {
            vec.push_back(make_pair(j.first, j.second));
        }
        sort(vec.begin(),vec.end(),comp);
        int ans = 0;
        for(auto i : vec)
        {
            cout << i.first << " " << i.second << endl;
            int occur = i.second;
            while(store.count(occur) && occur > 0)
            {
                occur--;
            }
            ans+=abs(i.second - occur);
            store.insert(occur);
        }
        return(ans);
    }
};