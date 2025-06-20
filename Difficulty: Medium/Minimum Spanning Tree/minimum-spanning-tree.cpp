class DSU
{
    vector<int> rank,parent,size;
public:
    DSU(int n)
    {
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
            parent[i]=i; // initially each node is its own parent
    }
    int findupar(int node)
    {
        if(parent[node]==node)
            return node;
        return parent[node]=findupar(parent[node]); // recursively find the parent
    }
    void unionbysize(int u,int v)
    {
        int upu=findupar(u);
        int upv=findupar(v);

        if(upu==upv)  return;

        if(size[upu]<size[upv])
        {
            parent[upu]=upv;
            size[upv]+=size[upu];
        }
        else
        {
            parent[upv]=upu;
            size[upu]+=size[upv];
        }
    }
};
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<pair<int,pair<int,int>>> edges;
        for(int u=0;u<V;u++)
        {
            for(auto j:adj[u])
            {
                int wt=j[1],v=j[0];
                if(u<v)
                edges.push_back({wt,{u,v}});
            }
        }
        sort(edges.begin(),edges.end());
        DSU dsu(V);
        int sum=0;
        for(auto i:edges)//Kruskal's algo
        {
            auto p=i.second;
            int wt=i.first,u=p.first,v=p.second;
            if(dsu.findupar(u)!=dsu.findupar(v))
            {
                dsu.unionbysize(u,v);
                sum+=wt;
            }
        }
        return sum;
    }
};