//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int func(vector<int>& dp,vector<int>& height,int i)
    {
        if(i==0)
        return 0;
        
        int one,two;
        if(dp[i]!=INT_MAX)
        return dp[i];
        
        one=func(dp,height,i-1)+ abs(height[i]-height[i-1]);
        if(i==1)
        dp[i]=one;
        else
        {
            two=func(dp,height,i-2)+ abs(height[i]-height[i-2]);
            dp[i]=min(one,two);
        }
        
        
        return dp[i];
    }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        if(n==1)
        return 0;
        
        vector<int> dp(n,INT_MAX);
        
        return func(dp,height,n-1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends