class Solution {
  public:
  vector<string> ans;
  int n;
    void f(int i,string& sub,string s)
    {
        if(i==n)
        {
            if(sub.size())
            ans.push_back(sub);
            return;
        }
        //pick
        sub.push_back(s[i]);
        f(i+1,sub,s);
        sub.pop_back();
        
        //not pickup
        f(i+1,sub,s);
    }
    vector<string> AllPossibleStrings(string s) {
        // Code here
        n=s.size();
        string sub="";
        f(0,sub,s);
        sort(ans.begin(),ans.end());
        return ans;
    }
};