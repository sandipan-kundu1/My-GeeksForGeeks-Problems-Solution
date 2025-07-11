class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        unordered_map<int,int> hash;
        for(int i=0;i<n;i++)
        {
            hash[arr[i]]++;
            if(hash[arr[i]]>floor((float)n/2))
            return arr[i];
        }
        return -1;
    }
};