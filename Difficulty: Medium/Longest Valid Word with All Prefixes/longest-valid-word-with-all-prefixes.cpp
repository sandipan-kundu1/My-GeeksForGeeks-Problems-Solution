struct Node{
    Node* links[26];
    bool flag=false;
};

class Trie {
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
            int ind=word[i]-'a';
            if(!temp->links[ind])
            {
                temp->links[ind]=new Node();
            }
            temp=temp->links[ind];
        }
        temp->flag=true;
    }
    
    bool search(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
            int ind=word[i]-'a';
            if(!temp->links[ind])
            return false;
            temp=temp->links[ind];
        }
        return temp->flag;
    }
    
    bool startsWith(string prefix) {
        Node* temp=root;
        for(int i=0;i<prefix.size();i++)
        {
            int ind=prefix[i]-'a';
            if(!temp->links[ind])
            return false;
            temp=temp->links[ind];
        }
        return true;
    }
};

class Solution {
public:
    string longestValidWord(vector<string>& words) {
        // code here
        Trie trie;
        for(string word:words)
        trie.insert(word);
        string longest="";
        for(string word:words)
        {
            string prefix="";
            bool ok=true;
            for(int i=0;i<word.size();i++)
            {
                prefix+=word[i];
                if(!trie.search(prefix))
                {
                    ok=false;
                    break;
                }
            }
            if(ok)
            {
                if(word.size()>longest.size() || (word.size()==longest.size() && word<longest))
                longest=word;
            }
        }
        return longest;
    }
};
