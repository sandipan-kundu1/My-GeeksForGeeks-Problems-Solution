// User function template for C++
class Solution {
  public:

    int search(string text, string pat) {
        // Your code goes here
        int n=text.size(),m=pat.size();
        for(int i=0;i<n;i++)
        {
            if(text[i]==pat[0])
            {
                if(text.substr(i,m)==pat)
                return 1;
            }
        }
        return 0;
    }
};