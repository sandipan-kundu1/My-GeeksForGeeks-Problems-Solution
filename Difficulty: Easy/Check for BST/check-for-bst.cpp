class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    bool check(Node *root,long long minval,long long maxval)
    {
        if(!root) return true;
        if(root->data<=minval || root->data>=maxval)
        return false;
        return check(root->left,minval,root->data) && check(root->right,root->data,maxval);
    }
    bool isBST(Node* root) {
        // Your code here
        return check(root,LLONG_MIN,LLONG_MAX);
    }//defining a range for each node, LLONG_MIN<root<LLONG_MAX
    //LLONG_MIN<root->left<root && root< root->right <LLONG_MAX
};