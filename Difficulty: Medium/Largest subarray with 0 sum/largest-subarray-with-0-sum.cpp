class Solution {
  public:
    int maxLength(vector<int>& A) {
        // code here
        unordered_map<int,int> hash;
        int n=A.size();
        vector<int> prefix(n+1);
        prefix[0]=0;
        prefix[0]=A[0];
        for(int i=0;i<n;i++)
        prefix[i+1]=prefix[i]+A[i];
        
        for(int i=0;i<=n;i++)
        {
            if(!hash.count(prefix[i]))
            hash[prefix[i]]=i;
        }
        int maxlen=0;
        for(int i=0;i<=n;i++)
        {
            if(hash[prefix[i]]!=i && i-hash[prefix[i]]>maxlen)
            {
                maxlen=i-hash[prefix[i]];
            }
        }
        return maxlen;
    }
};