class Solution {
  public:
    int removeDuplicates(vector<int> &A) {
        // code here
        int n=A.size();
        if(n==0 || n==1) return n;
        int cnt=1;
        int k=1;
        for(int i=1;i<n;i++)
        {
            if(A[i]!=A[i-1])
            {
                cnt++;
                A[k++]=A[i];
            }
        }
        return k;
        }
};