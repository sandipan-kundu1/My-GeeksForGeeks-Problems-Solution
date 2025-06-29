class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int l=0,r=0,jumps=0;
        while(r<arr.size()-1)
        {
            int farthest=0;
            for(int i=l;i<=r;i++)
            {
                farthest=max(farthest,i+arr[i]);
            }
            if(farthest==r)
            return -1;
            l=r+1;
            r=farthest;
            jumps++;
        }
        return jumps;
    }
};
