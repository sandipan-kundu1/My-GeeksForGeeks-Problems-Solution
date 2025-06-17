class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        //kahn's algo             indegree+queue(BFS)
        vector<int> indegre(V,0);
        for(auto edge:edges)
            indegre[edge[1]]++;
            
        vector<vector<int>> adj(V);
        for(auto edge:edges)
        adj[edge[0]].push_back(edge[1]);
        vector<int> res;
        queue<int> q;
        for(int i = 0; i < V; i++)
        if(indegre[i] == 0)
        q.push(i);

        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            res.push_back(node);
            for(auto nei:adj[node])
            {
                indegre[nei]--;
                if(indegre[nei]==0)
                q.push(nei);    
            }
        }
        return res;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int> res;
        res=topoSort(V,edges);
        if(res.size()<V)
        return true;
        return false;
    }
};
