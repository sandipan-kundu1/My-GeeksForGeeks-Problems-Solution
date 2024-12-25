//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    // Step 1: Create adjacency list
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Undirected graph
    }

    // Step 2: Initialize distances and parent arrays
    vector<int> dist(n + 1, 1e9); // Distance array
    vector<int> parent(n + 1);    // Parent array for path reconstruction
    for (int i = 1; i <= n; i++) parent[i] = i;
    dist[1] = 0;

    // Step 3: Priority queue for Dijkstra's algorithm
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1}); // {distance, node}

    while (!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto& neighbor : adj[node]) {
            int nb = neighbor.first;
            int wt = neighbor.second;

            if (dis + wt < dist[nb]) {
                dist[nb] = dis + wt;
                parent[nb] = node;
                pq.push({dist[nb], nb});
            }
        }
    }

    // Step 4: Path reconstruction
    if (dist[n] == 1e9) return {-1}; // No path exists

    vector<int> path;
    int node = n;
    while (parent[node] != node) {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());

    // Add the total weight to the beginning of the path
    path.insert(path.begin(), dist[n]);
    return path;
}
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends