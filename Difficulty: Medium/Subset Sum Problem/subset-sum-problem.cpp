//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool f(int ind,int target,vector<int>& arr, vector<vector<int>>& dp)
    {
        //base case
        if(target==0)
        return true;
        if(ind==0)
        {
            if(arr[ind]==target)
            return true;
            else
            return false;
        }
        
        if(dp[ind][target]!=-1)
        return dp[ind][target];
        
        bool nottake=f(ind-1,target,arr,dp);
        bool take=false;
        if(target>=arr[ind])
        take=f(ind-1,target-arr[ind],arr,dp);
        return dp[ind][target]=take || nottake;
    }
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        
        return f(n-1,target,arr,dp);
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