//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    const long long MOD = 1e9 + 7;

long long int fib(vector<long long int>& dp, int n) {
    // Base case
    if (n <= 1)
        return n;

    // If already computed, return from dp
    if (dp[n] != -1)
        return dp[n];

    // Correct modular arithmetic
    dp[n] = (fib(dp, n - 1) + fib(dp, n - 2)) % MOD;
    return dp[n];
}

long long int topDown(int n) {
    if (n <= 1) // Handle edge case
        return n;

    // Initialize dp array with -1
    vector<long long int> dp(n + 1, -1);

    // Call recursive helper function
    return fib(dp, n);
}

long long int bottomUp(int n) {
    if (n <= 1) // Handle edge case
        return n;

    // Initialize dp array
    vector<long long int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    // Fill dp array iteratively
    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    // Return the nth Fibonacci number
    return dp[n];
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends