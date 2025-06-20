class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<int> vis(V,0);
        pq.push({0,0}); //wt,node
        vis[0]=1;
        int sum=0;
        while(!pq.empty())
        {
            auto p=pq.top();
            pq.pop();
            int w=p[0],node=p[1];
            if(!vis[node])
            {
                sum+=w;
                vis[node]=1;
            }
            
            for(auto n:adj[node])
            {
                int nei=n[0],wt=n[1];
                if(!vis[nei])
                {
                    pq.push({wt,nei});
                    
                }
            }
        }
        return sum;
    }
};