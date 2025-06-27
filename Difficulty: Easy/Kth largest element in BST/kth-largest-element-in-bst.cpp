/*The Node structure is defined as
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

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
  public:
    int ans=-1;
    void revinorder(Node* root,int &k)
    {
        if(!root)
        return;
        revinorder(root->right,k);
        if(k==1)
        ans=root->data;
        k--;
        revinorder(root->left,k);
    }
    int kthLargest(Node *root, int k) {
        // Your code here
        revinorder(root,k);
        return ans;
    }
};