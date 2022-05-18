class Solution {
public:
    bool dfs(int node, set<int> &to_visit, set<int> &visiting, set<int> &visited,
        vector<vector<int>>& adj)
        {
            to_visit.erase(node);
            visiting.insert(node);
            for(int i : adj[node])
            {
                if(visiting.find(i)!=visiting.end()) return(false);
                if(visited.find(i)!=visited.end()) continue;
                if(to_visit.find(i)!=to_visit.end())
                { 
                    if(dfs(i,to_visit,visiting,visited,adj)==false)
                    {
                        return(false);
                    }   
                }
            }
            visiting.erase(node);
            visited.insert(node);
            return(true);
        
    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        // detect a cycle in a directed graph
        set<int> to_visit;
        set<int> visiting;
        set<int> visited;
        int n = numCourses;
        vector<vector<int>> adj(n,vector<int>());
        for(int i=0;i<pre.size();i++)
        {
            adj[pre[i][0]].push_back(pre[i][1]);
        }
        for(int i=0;i<n;i++) to_visit.insert(i);
        while((int)to_visit.size()>0)
        {
            int start  = *to_visit.begin();
            if(dfs(start,to_visit,visiting,visited,adj)==false) return(false);
        }
        return(true);
    }
};