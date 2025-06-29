class Solution {
  public:
    int maxChildren(vector<int> &greed, vector<int> &cookie) {
        sort(greed.begin(),greed.end());
        sort(cookie.begin(),cookie.end());
        int i=0,j=0,count=0;
        while(i<greed.size() && j<cookie.size()){
            if(cookie[j]>=greed[i]){
                count++;
                i++;
            }
            j++;
        }
        return count;
    }
};
