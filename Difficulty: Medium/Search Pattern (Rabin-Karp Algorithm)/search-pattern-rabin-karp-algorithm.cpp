#define ll long long
class Solution {
  public:
    const int p=31;
    const int M=1e9+9;
    long long modinv(long long a, long long m) {
        return binexp(a, m - 2, m);
    }

    long long binexp(long long a, long long b, long long m) {
        long long res = 1;
        while(b > 0) {
            if(b & 1)
                res = (res * a) % m;
            a = (a * a) % m;
            b >>= 1;
        }
        return res;
    }
    vector<int> search(string &pat, string &txt) {
        // code here.
        vector<int> res;
        int n=txt.size(),m=pat.size();
        
        ll pat_hash=0,txt_hash=0,power=1;
        for(int i=0;i<m;i++)
        {
            txt_hash=(txt_hash+(txt[i]-'a'+1) *power)%M;
            pat_hash=(pat_hash+(pat[i]-'a'+1)*power)%M;
            if(i<m-1)
            power=(power*p)%M;
        }
        
        if(pat_hash==txt_hash)
        res.push_back(1);
        ll inv_p = modinv(p, M);
        //string rolling
        for(int i=m;i<n;i++)
        {
            txt_hash=(txt_hash - (txt[i-m]-'a'+1)+M)%M;//removing leftmost
            txt_hash=(txt_hash* inv_p)%M; //adjusting power of middle ones
            
            txt_hash=(txt_hash+(txt[i]-'a'+1)*power)%M;
            
            if(txt_hash==pat_hash)
            res.push_back(i-m+2); //1 based index
        }
        return res;
    }
};