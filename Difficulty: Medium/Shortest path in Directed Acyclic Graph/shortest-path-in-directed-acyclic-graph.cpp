// User function Template for C++
class Solution {
  public:
    void dfs(int node,vector<int>& vis,vector<vector<pair<int,int>>>& adj,stack<int>& s)
    {
        vis[node]=1;
        for(auto p:adj[node])
        {
            if(!vis[p.first])
            dfs(p.first,vis,adj,s);
        }
        s.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto edge:edges)
        {
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
        vector<int> vis(V,0);
        stack<int> s;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            dfs(i,vis,adj,s);
        }
        
        vector<int> dist(V,1e9);
        dist[0]=0;
        
        while(!s.empty())
        {
            int node=s.top();
            s.pop();
            for(auto p:adj[node])
            {
                dist[p.first]=min(dist[p.first],dist[node]+p.second);
            }
        }
        for(int i=0;i<dist.size();i++)
        if(dist[i]==1e9)
        dist[i]=-1;
        return dist;
    }
};
