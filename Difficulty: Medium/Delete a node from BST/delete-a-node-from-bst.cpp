class Solution {
  public:
    Node* findMin(Node* node) {
        while(node && node->left) node = node->left;
        return node;
    }

    Node* deleteNode(Node* root, int X) {
        if(!root) return nullptr;
        if(X < root->data) root->left = deleteNode(root->left, X);
        else if(X > root->data) root->right = deleteNode(root->right, X);
        else {
            if(!root->left) return root->right;
            if(!root->right) return root->left;
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }
};
