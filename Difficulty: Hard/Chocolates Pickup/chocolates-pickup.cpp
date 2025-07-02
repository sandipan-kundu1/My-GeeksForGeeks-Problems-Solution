class Solution {
  public:
  int N,M;
  vector<int> dj={-1,0,1};
    int f(int i,int j1,int j2, vector<vector<int>>& grid,vector<vector<vector<int>>>& dp)
    {
        if(i==N-1)
        {
            if(j1==j2)
            return grid[i][j1];
            else
            return grid[i][j1]+grid[i][j2];
        } 
        if(dp[i][j1][j2]!=-1)
        return dp[i][j1][j2];
        
        int maxi=0;
        for(int x=0;x<3;x++)
        {
            for(int y=0;y<3;y++)
            {
                int nj1=j1+dj[x];
                int nj2=j2+dj[y];
                if(nj1>=0 && nj2>=0 && nj1<M && nj2<M)
                {
                    if(j1==j2)
                    {
                        maxi=max(maxi,grid[i][j1]+ f(i+1,nj1,nj2,grid,dp));
                    }
                    else
                    {
                        maxi=max(maxi,grid[i][j1]+grid[i][j2]+ f(i+1,nj1,nj2,grid,dp));
                    }
                }
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        N=n,M=m;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return f(0,0,m-1,grid,dp);
    }
};