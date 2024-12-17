//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool detect(int i,int parent,vector<vector<int>>& adj,vector<int> &vis)
  {
      
      vis[i]=1;
      
          for(auto j:adj[i])
          {
              if(!vis[j])
              {
                  if(detect(j,i,adj,vis))
                  return true;
                  
              }
              else if(vis[j] && j!=parent)
              return true;
          }
      
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int V=adj.size();
        vector<int> vis(V,0);
        for(int i=0;i<V;i++)
        {
            
            if(!vis[i])
            {
                if(detect(i,-1,adj,vis))
                return true;
            }
                
            
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends