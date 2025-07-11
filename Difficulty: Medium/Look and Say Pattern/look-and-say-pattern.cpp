class Solution {
public:
    string helper(string s)
    {
        if(s.size()==0)
        return "";
        int cnt=0;
        string ans="";
        int i=0;
        for(;i<s.size();i++)
        {
            if(i!=0 && s[i]!=s[i-1])
            {
                ans+=to_string(cnt) + s[i-1];
                cnt=0;
            }
            cnt++;
        }
        ans+=to_string(cnt) + s.back();
        return ans;
    }
    string countAndSay(int n) {
        int i=1;
        string s="1";
        while(i<n)
        {
            s=helper(s);
            i++;
        }
        return s;
    }
};