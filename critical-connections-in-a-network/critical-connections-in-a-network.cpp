class Solution {
public:
    int time = 0;
    void dfs(int index, vector<vector<int>> &adj, vector<int> &highTime, vector<int> &lowTime,                           vector<int> &parent, vector<vector<int>> &ans, vector<bool> &vis)
    {
        vis[index] = true;
        highTime[index] = lowTime[index] = time;
        time++;
        for(int neigh : adj[index])
        {
            if(!vis[neigh])
            {
                parent[neigh] = index;
                dfs(neigh,adj,highTime,lowTime,parent,ans,vis);
                lowTime[index] = min(lowTime[index],lowTime[neigh]);
                if(highTime[index] < lowTime[neigh])
                {
                    ans.push_back({index,neigh});
                }
            }
            else
            {
                if(parent[index]!=neigh)
                {
                    lowTime[index] = min(lowTime[index], highTime[neigh]);
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n,vector<int>());
        for(auto i : connections)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> highTime(n);
        vector<int> lowTime(n);
        vector<bool> vis(n,false);
        vector<vector<int>> ans;
        vector<int> parent(n);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                dfs(i,adj,highTime,lowTime,parent,ans,vis);
        }
        return(ans);
    }
};
