class Solution {
  public:
    int f(int i,vector<int>& height,vector<int> &dp)
    {
        if(i==0)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int one=INT_MAX,two=INT_MAX;
        one=abs(height[i]-height[i-1])+f(i-1,height,dp);
        if(i>1)
        two=abs(height[i]-height[i-2])+f(i-2,height,dp);
        return dp[i]=min(one,two);
    }
    int minCost(vector<int>& height) {
        int n=height.size();
        vector<int> dp(n,-1);
        return f(n-1,height,dp);
    }
};