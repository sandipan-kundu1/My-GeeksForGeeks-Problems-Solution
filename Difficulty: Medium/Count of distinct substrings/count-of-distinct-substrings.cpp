/*You are required to complete this method */
struct Node{
    Node* links[26];
};

class Trie {
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    void freeNode(Node* node) {
        for (int i = 0; i < 26; i++) {
            if (node->links[i]) freeNode(node->links[i]);
        }
        delete node;
    }

    ~Trie() {
        freeNode(root);
    }

    int helper(string s) {
        int n=s.size(),cnt=0;
        for(int i=0;i<n;i++)
        {
            Node* temp=root;
            for(int j=i;j<n;j++)
            {
                int ind=s[j]-'a';
                if(!temp->links[ind])
                {
                    temp->links[ind]=new Node();
                    cnt++;
                }
                temp=temp->links[ind];
            }
            
        }
        return cnt+1;
    }
};
int countDistinctSubstring(string s){
    Trie trie;
    return trie.helper(s);
}