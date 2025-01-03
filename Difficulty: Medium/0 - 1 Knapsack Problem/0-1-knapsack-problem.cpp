//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int f(int ind, int capacity,vector<int> &val, vector<int> &wt,vector<vector<int>>& dp)
    {
        //base case
        if(capacity==0)
        return 0;
        if(ind==0)
        {
            if(capacity>=wt[0])
            return val[0];
            else
            return 0;
        }
        
        if(dp[ind][capacity]!=-1)
        return dp[ind][capacity];
        
        int notpick=0+f(ind-1,capacity,val,wt,dp);
        int pick=0;
        if(capacity>=wt[ind])
        pick=val[ind]+ f(ind-1, capacity-wt[ind],val,wt,dp);
        return dp[ind][capacity]=max(pick,notpick);
    }
    // Function to return max value that can be put in knapsack of capacity.
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
        return f(n-1,capacity,val,wt,dp);
    }
};

//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapSack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends