class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
        sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b){
        return a[1]<b[1];
        });  //sorted by end time(lambda function)
        int cnt=0,time=INT_MIN;
        for(auto p:intervals)
        {
            int start=p[0],end=p[1];
            if(start>=time)
            {
                time=end;
            }
            else
            cnt++;
        }
        return cnt;
    }
};
