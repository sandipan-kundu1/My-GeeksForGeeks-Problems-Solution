class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n=s1.size(),m=s2.size();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        int maxlen=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=1+ dp[i-1][j-1];
                    maxlen=max(maxlen,dp[i][j]);
                }
                else
                dp[i][j]=0;
            }
        }
        return maxlen;
    }
};