//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // Step 1: Find XOR of all elements
        long long int xor_all = 0;
        for(long long int i = 0; i < N; i++) {
            xor_all ^= Arr[i];
        }
        
        // Step 2: Find a set bit in xor_all (rightmost set bit)
        long long int set_bit = xor_all & ~(xor_all - 1);
        
        // Step 3: Divide elements into two groups and find the odd occurring numbers
        long long int x = 0, y = 0;
        for(long long int i = 0; i < N; i++) {
            if(Arr[i] & set_bit) {
                x ^= Arr[i];
            } else {
                y ^= Arr[i];
            }
        }
        
        // Ensure the result is in descending order
        vector<long long int> ans = {x, y};
        if(ans[0] < ans[1]) {
            swap(ans[0], ans[1]);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends