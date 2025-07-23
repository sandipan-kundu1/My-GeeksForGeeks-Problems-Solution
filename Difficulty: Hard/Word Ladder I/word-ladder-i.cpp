class Solution {
  public:
    int wordLadderLength(string startWord, string targetWord,
                         vector<string>& wordList) {
        // Code here
        unordered_set<string> list(wordList.begin(),wordList.end());
        if(!list.count(targetWord))
        return 0;
        queue<pair<string ,int>> q;
        q.push({startWord,1});
        while(!q.empty())
        {
            string word=q.front().first;
            int level=q.front().second;
            q.pop();
            if(word==targetWord)
            return level;
            for(int i=0;i<word.size();i++)
            {
                char orig=word[i];
                for(char c='a';c<='z';c++)
                {
                    word[i]=c;
                    if(list.count(word))
                    {
                        q.push({word,level+1});
                        list.erase(word);
                    }
                }
                word[i]=orig;
            }
        }
        return 0;
    }
};