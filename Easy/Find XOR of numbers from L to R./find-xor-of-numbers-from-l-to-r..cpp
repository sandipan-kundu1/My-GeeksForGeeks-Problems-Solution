//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findXOR(int l, int r) {
        return xorTillN(l - 1) ^ xorTillN(r);
    }

  private:
    int xorTillN(int n) {
        switch (n % 4) {
            case 0: return n;        // If n is a multiple of 4
            case 1: return 1;        // If n % 4 == 1
            case 2: return n + 1;    // If n % 4 == 2
            case 3: return 0;        // If n % 4 == 3
        }
        return 0; // To satisfy the compiler, this will never be reached
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    }
}
// } Driver Code Ends