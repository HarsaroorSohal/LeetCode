class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int inf = 1e9 + 7;
        vector<vector<int>> dp(n,vector<int>(k+2,inf)); //min cost to get to a node with k stops.
        dp[src][0] = 0;
        vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
        for(auto v : flights)
        {
            adj[v[0]].push_back({v[1],v[2]});
        }
        priority_queue<pair<int,pair<int,int>>
            ,vector<pair<int,pair<int,int>>>
            , greater<pair<int,pair<int,int>>>> q; //dist,(k,node);
        q.push({0,{0,src}});
        while(!q.empty())
        {
            auto curr = q.top();
            q.pop();
            int i = curr.second.second;
            int vis = curr.second.first;
            if(vis>k) continue;
            int dis = curr.first;
            for(auto p : adj[i])
            {
                if(dp[p.first][vis+1] > dis + p.second)
                {
                    dp[p.first][vis+1] = dis + p.second;
                    q.push({dp[p.first][vis+1],{vis+1,p.first}});
                }
            }
        }
        int ans = inf;
        for(int i : dp[dst]) ans = min(ans,i);
        if(ans==inf) return(-1);
        return(ans);
    }
};
