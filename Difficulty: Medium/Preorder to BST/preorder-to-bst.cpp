class Solution {
  public:
    int idx = 0;

    Node* build(int pre[], int size, int bound) {
        if (idx == size || pre[idx] > bound) return NULL;
        Node* root = newNode(pre[idx++]);
        root->left = build(pre, size, root->data);
        root->right = build(pre, size, bound);
        return root;
    }

    Node* Bst(int pre[], int size) {
        return build(pre, size, INT_MAX);
    }
};
