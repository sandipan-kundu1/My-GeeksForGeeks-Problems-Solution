/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    bool dfs(Node *l,Node* r)
    {
        if(!l || !r)//if both null true,one null false
        return l==r;
        if(l->data!=r->data)
        return false;
        return dfs(l->left,r->right) && dfs(l->right,r->left);//as mirror image comparing left's left with right's right,left's right with right'sleft
    }
    bool isSymmetric(Node* root) {
        // Code here
        if(!root)   return true;
        return dfs(root->left,root->right);
    }
};