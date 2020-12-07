class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        int n = S.size();
        int end = 0;
        unordered_set<char> s;
        unordered_map<char,int> max_index;
        for(int i=0;i<n;i++)
        {
            if(i>max_index[S[i]]) max_index[S[i]] = i;
        }
        int prev = 0;
        while(end<n)
        {
            s.insert(S[end]);
            bool can_break = true;
            for(char c : s)
            {
                if(end<max_index[c])
                {
                    can_break = false;
                    break;
                }
            }
            if(can_break)
            {
                ans.push_back(end+1-prev);
                prev = end+1;
                s.clear();
            }
            end++;
        }
        return(ans);
    }
};
