//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    bool prime(int k) {
        if (k <= 1) return false;
        if (k <= 3) return true;
        if (k % 2 == 0 || k % 3 == 0) return false;
        for (int i = 5; i * i <= k; i += 6) {
            if (k % i == 0 || k % (i + 2) == 0) return false;
        }
        return true;
    }
	public:
	vector<int>AllPrimeFactors(int N) {
	    set<int> st;
        for (int i = 2; i * i <= N; i++) {
            while (N % i == 0) {
                if (prime(i)) {
                    st.insert(i);
                }
                N /= i;
            }
        }
        if (N > 1 && prime(N)) {
            st.insert(N);
        }
        vector<int> result(st.begin(), st.end());
        return result;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends