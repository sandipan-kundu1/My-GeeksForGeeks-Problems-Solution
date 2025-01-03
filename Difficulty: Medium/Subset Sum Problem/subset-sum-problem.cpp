//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<vector<bool>> dp(n,vector<bool>(target+1,false));
        
        for(int i=0;i<n;i++)
        dp[i][0]=true;
        dp[0][arr[0]]=true;
       
        for(int i=1;i<n;i++)
        {
            for(int k=1;k<=target;k++)
            {
                bool nottake=dp[i-1][k];
                bool take=false;
                if(k>=arr[i])
                take=dp[i-1][k-arr[i]];
                dp[i][k]=take | nottake;
            }
        }
        return dp[n-1][target];
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends