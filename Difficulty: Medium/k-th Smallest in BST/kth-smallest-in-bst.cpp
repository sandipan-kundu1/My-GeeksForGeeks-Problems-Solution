/*Complete the function below

struct Node {
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
    // Return the Kth smallest element in the given BST
    int ans=-1;
    void inorder(Node* root,int &k)
    {
        if(!root)
        return;
        inorder(root->left,k);
        if(k==1)
        ans=root->data;
        k--;
        inorder(root->right,k);
    }
    int kthSmallest(Node *root, int k) {
        // add code here.
        inorder(root,k);
        return ans;
    }
};