bool search(Node* root, int x) {
    if (!root) return false;
    if (root->data == x) return true;
    if (x < root->data) return search(root->left, x);
    return search(root->right, x);
}
