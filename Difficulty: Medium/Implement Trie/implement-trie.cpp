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
    
    bool isPrefix(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
            int ind=word[i]-'a';
            if(!temp->links[ind])
            return false;
            temp=temp->links[ind];
        }
        return true;
    }
};