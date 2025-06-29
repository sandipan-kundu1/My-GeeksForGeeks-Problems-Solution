// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        int n=bt.size();
        sort(bt.begin(),bt.end());
        int totalwait=0,curwait=0;
        for(int i=1;i<n;i++)
        {
            curwait+=bt[i-1];
            totalwait+=curwait;
        }
        return totalwait/n;
    }
};