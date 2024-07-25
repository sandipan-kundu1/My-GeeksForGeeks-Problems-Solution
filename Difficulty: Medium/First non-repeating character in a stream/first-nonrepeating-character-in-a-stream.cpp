//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    string s="";
		    map<char,int> hash;
		  //  vector<int> visited(26,0);
		    queue<int> q;
		    for(int i=0;i<A.size();i++){
		       
		       hash[A[i]]++;
		       q.push(A[i]);
		       while(!q.empty()){
		           if(hash[q.front()]>1)
		           q.pop();
		           else{
		               s.push_back(q.front());
		               break;
		           }
		       }
		       if(q.empty())
		       s.push_back('#');
		        
		    }
		    return s;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends