class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) {
        // Code here
    int n=matrix.size();
    vector<int> dx={1,0};
    vector<int> dy={0,1};//right,down
    vector<int> res;
    vector<vector<int>> vis(n,vector<int>(n,0));
    queue<pair<int,int>> q;
    q.push({0,0});
    
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            auto p=q.front();
            int row=p.first,col=p.second;
            q.pop();
            res.push_back(matrix[row][col]);
            for(int i=0;i<2;i++)
            {
                int nx=col+dx[i];
                int ny=row+dy[i];
                if(nx<n && ny<n && !vis[ny][nx])
                {
                    q.push({ny,nx});
                    vis[ny][nx]=1;
                }
            }
        }
    }
    return res;
    }
};