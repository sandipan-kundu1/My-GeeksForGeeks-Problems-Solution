//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfscheck(int i,vector<vector<int>> adj,vector<int>& vis,vector<int>& pathvis)
    {
        vis[i]=1;
        pathvis[i]=1;
        for(auto it:adj[i])
        {
            if(!vis[it])
            {
                if(dfscheck(it,adj,vis,pathvis))
                return true;
            }
            else if(pathvis[it]==1)
            return true;
        }
        pathvis[i]=0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> adj) {
        vector<int> vis(V,0);
        vector<int> pathvis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfscheck(i,adj,vis,pathvis))
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends