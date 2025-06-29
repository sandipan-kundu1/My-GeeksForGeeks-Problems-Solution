// User function Template for C++

class Solution {
  public:
    // Function to check if we can reach the last index from 0th index.
    bool canReach(vector<int> &arr) {
        // code here
        int maxind=0;
        for(int i=0;i<arr.size();i++)
        {
            if(i>maxind)
            return false;
            maxind=max(maxind,i+arr[i]);
        }
        return true;
    }
};