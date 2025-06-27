/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* suc=NULL,*pre=NULL;
        Node* node=root;
        while(node)
        {
            if (node->data == key) {
                // Predecessor: max value in left subtree
                if (node->left) {
                    Node* temp = node->left;
                    while (temp->right) temp = temp->right;
                    pre = temp;
                }
                // Successor: min value in right subtree
                if (node->right) {
                    Node* temp = node->right;
                    while (temp->left) temp = temp->left;
                    suc = temp;
                }
                break;
            }
            else if(node->data<key)
            {
                pre=node;
                node=node->right;
            }
            else
            {
                suc=node;
                node=node->left;
            }
        }
        return {pre,suc};
    }
};