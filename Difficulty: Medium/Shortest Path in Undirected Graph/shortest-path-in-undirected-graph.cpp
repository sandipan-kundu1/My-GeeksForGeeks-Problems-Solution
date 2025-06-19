class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int V=adj.size();
        vector<int> dist(V,1e9);
        dist[src]=0;
        queue<int> q;
        q.push(src);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto nei:adj[node])
            {
                if(dist[node]+1<dist[nei])
                {
                    dist[nei]=dist[node]+1;
                    q.push(nei);
                }
            }
        }
        for(int &i:dist)
        if(i==1e9)  i=-1;  //unreachable node
        return dist;
    }
};