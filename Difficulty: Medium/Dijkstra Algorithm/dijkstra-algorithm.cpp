//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        int V=adj.size();
        vector<int> dist(V,1e9);
        set<pair<int,int>> s;
        s.insert({0,src});
        dist[src]=0;
        while(!s.empty())
        {
            auto it=s.begin();
            
            int dis=it->first;
            int node=it->second;
            s.erase(it);
            for(auto i:adj[node])
            {
                int nb=i.first;
                int wt=i.second;
                if(dis+wt< dist[nb])
                {
                    
                    if(dist[nb]!=1e9) //when the node has been already traversed, replace the pair in set
                    {
                        s.erase({dist[nb],nb});
                    }
                    s.insert({dis+wt,nb});
                    dist[nb]=dis+wt;
                }
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends