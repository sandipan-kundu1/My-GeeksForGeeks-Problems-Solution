// User Fuction template for C++
/*
// Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to return maximum path sum from any node in a tree.
    int maxpath(Node* root,int &maxi)
    {
        if(!root)   return 0;

        int lsum=maxpath(root->left,maxi);
        int rsum=maxpath(root->right,maxi);
        if(lsum<0)  lsum=0;
        if(rsum<0)  rsum=0;
        maxi=max(maxi,root->data+lsum+rsum);
        return root->data+max(lsum,rsum);
    }
    int findMaxSum(Node *root) {
        // code here
        int maxi=INT_MIN;
        maxpath(root,maxi);
        return maxi;
    }
};