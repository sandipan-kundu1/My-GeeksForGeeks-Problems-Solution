class Solution {
  public:
    Node* build(int instart, int inend, int& preIndex, vector<int>& inorder, vector<int>& preorder, unordered_map<int, int>& mp) {
        if (instart > inend) return NULL;
        Node* root = new Node(preorder[preIndex++]);
        int idx = mp[root->data];
        root->left = build(instart, idx - 1, preIndex, inorder, preorder, mp);
        root->right = build(idx + 1, inend, preIndex, inorder, preorder, mp);
        return root;
    }

    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
        int preIndex = 0;
        return build(0, inorder.size() - 1, preIndex, inorder, preorder, mp);
    }
};
