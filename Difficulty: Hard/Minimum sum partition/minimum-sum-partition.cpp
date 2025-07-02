class Solution {

  public:
    int minDifference(vector<int>& arr) {
        // Your code goes here
        if(arr.empty())    return 0;
        int total=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        total+=arr[i];
        vector<vector<bool>> dp(n,vector<bool>(total+1,false));
        for(int i=0;i<n;i++)    dp[i][0]=true;

        if(arr[0]<=total)
        dp[0][arr[0]]=true;

        for(int i=1;i<n;i++)
        {
            for(int k=1;k<=total;k++)
            {
                bool nottake=dp[i-1][k];
                bool take=false;
                if(k>=arr[i])
                take=dp[i-1][k-arr[i]];
                dp[i][k]=take | nottake;
            }
        }
        //now the dp table formed we can traverse the bottom most row to check any sum value 0 to total
        //then, find given condition for which sum is possible
        int mini=1e9;
        for(int sum=0;sum<=total/2;sum++)
        {
            if(dp[n-1][sum])
            mini=min(mini,abs((total-sum)-sum));
        }
        return mini;
    }
};
