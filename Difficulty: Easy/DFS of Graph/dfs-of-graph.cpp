//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void getdfs(int i,vector<int> &dfs,vector<vector<int>>& adj,int vis[] )
    {
        vis[i]=1;
        dfs.push_back(i);
        for(auto it:adj[i])
        {
            if(!vis[it])
            getdfs(it,dfs,adj,vis);
        }
    }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        int V=adj.size();
        int vis[V]={0};
        vector<int> dfs;
        getdfs(0,dfs,adj,vis);
        return dfs;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends