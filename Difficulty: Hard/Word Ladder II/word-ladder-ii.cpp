// User function Template for C++

class Solution {
  public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string>& wordList) {
        // code here
        unordered_set<string> st(wordList.begin(),wordList.end());
        vector<vector<string>> ans;
        queue<vector<string>> q;
        vector<string> usedonlevel;
        usedonlevel.push_back(beginWord);
        q.push({beginWord});
        int level=0;
        while(!q.empty())
        {
            auto seq=q.front();
            q.pop();
            string word=seq.back();
            if(seq.size()>level)
            {
                level++;
                for(auto it:usedonlevel)
                st.erase(it);
                usedonlevel.clear();
            }
            if(word==endWord)
            {
                if(ans.size()==0)
                ans.push_back(seq);
                else if(ans[0].size()==seq.size())
                ans.push_back(seq);
                continue;
            }
            
            for(int i=0;i<word.size();i++)
            {
                char orig=word[i];
                for(char c='a';c<='z';c++)
                {
                    word[i]=c;
                    if(c!=orig && st.count(word))
                    {
                        seq.push_back(word);
                        q.push(seq);
                        usedonlevel.push_back(word);
                        seq.pop_back();
                    }
                }
                word[i]=orig;
            }
            st.erase(word);
        }
        return ans;
    }
};