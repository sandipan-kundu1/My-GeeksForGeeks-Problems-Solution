/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    // Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root, int n1, int n2) {
        // Your code here
        if(root==NULL || root->data==n1 || root->data==n2)
        return root;//whenever we find p,q ,we return p or q from that node, if not then null from leaf node

        //at any internal node, if both l and r subtree null, return null
        //if one of them not null return that, cuz that one ensures one of the target present there
        //at lca,both left and right will return not null, then return that lca node from there
        //like in the e.g. 5 returns 5 and 1 returns 1 ,at 3 both not null, return 3 which is lca.

        Node* left=lca(root->left,n1,n2);
        Node* right=lca(root->right,n1,n2);
        if(left==NULL)
        return right;
        else if(right==NULL)
        return left;
        else //both not null,lca found
        return root;
    }
};