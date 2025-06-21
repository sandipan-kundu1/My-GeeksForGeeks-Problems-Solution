struct Node{
    Node* links[26];
    int countPrefix=0;
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
            temp->countPrefix++;
        }
    }
    
    int countStarting(string prefix) {
        Node* temp=root;
        for(int i=0;i<prefix.size();i++)
        {
            int ind=prefix[i]-'a';
            if(!temp->links[ind])
            return 0;
            temp=temp->links[ind];
        }
        return temp->countPrefix;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie;
        for(string s:strs)
        trie.insert(s);
        string prefix="",word=strs[0],ans="";
        for(int i=0;i<word.size();i++)
        {
            prefix+=word[i];
            if(trie.countStarting(prefix)==strs.size())
            ans=prefix;
            else
            break;
        }
        return ans;
    }
};