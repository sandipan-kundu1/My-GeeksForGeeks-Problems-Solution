//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
    vector<int> orig;
    for(int i:arr)
    orig.push_back(i);
    
    sort(arr.begin(),arr.end());
    unordered_map<int,int> mp;
    int rank=1;
    for(int i=0;i<N;i++){
        mp[arr[i]]=rank;
        if( i<N-1 && arr[i+1]!=arr[i])
        rank++;
    }
    for(int i=0;i<N;i++){
        orig[i]=mp[orig[i]];
    }
    return orig;
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends