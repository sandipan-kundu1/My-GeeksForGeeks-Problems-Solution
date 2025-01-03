//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity.
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>> dp(n,vector<int>(capacity+1,0));
        vector<int> prev(capacity+1,0),cur(capacity+1);
        //base case
        for(int j=0;j<=capacity;j++)
        {
            if(j>=wt[0])
            prev[j]=val[0];
            else
            prev[j]=0;
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=capacity;j++)
            {
                int notpick=0+prev[j];
                int pick=0;
                if(j>=wt[i])
                pick=val[i]+ prev[j-wt[i]];
                cur[j]=max(pick,notpick);
            }
            prev=cur;
        }
        return prev[capacity];
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