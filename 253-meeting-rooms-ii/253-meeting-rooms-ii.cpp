class Solution {
    
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if(a[0] == b[0])
            return(a[1] < b[1]);
        return(a[0] < b[0]);
        
    }
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // sort(intervals.begin(),intervals.end(),comp);
        int mx = pow(10,6)+1;
        vector<int> v(mx+2,0);
        for(auto i : intervals)
        {
            v[i[0]]++;
            v[i[1]]--;
        }
        for(int i=1;i<mx+2;i++)
            v[i]+=v[i-1];
        int ans = 0;
        for(int i : v)
            ans = max(ans,i);
        return(ans);
        
    }
};