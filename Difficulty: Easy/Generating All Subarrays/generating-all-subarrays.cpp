// User function Template for C++
class Solution {
  public:
    vector<vector<int> > getSubArrays(vector<int>& arr) {
        // code here
        vector<vector<int>> ans;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            vector<int> v;
            for(int j=i;j<n;j++)
            {
                v.push_back(arr[j]);
                ans.push_back(v);
            }
        }
        return ans;
    }
};