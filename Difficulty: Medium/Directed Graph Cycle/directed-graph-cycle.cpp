class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathvis) {
        vis[node] = 1;
        pathvis[node] = 1;

        for(auto i : adj[node]) {
            if(!vis[i]) {
                if(dfs(i, adj, vis, pathvis)) return true;
            } else if(pathvis[i]) {
                return true;
            }
        }

        pathvis[node] = 0;
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int> vis(V, 0), pathvis(V, 0);
        vector<vector<int>> adj(V);
        for(auto edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
        }

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(dfs(i, adj, vis, pathvis)) return true;
            }
        }

        return false;
    }
};
