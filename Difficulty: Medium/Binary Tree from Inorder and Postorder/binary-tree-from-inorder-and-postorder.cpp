class Solution {
  public:
    Node* build(int instart, int inend, int& postIndex, vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& mp) {
        if (instart > inend) return NULL;
        Node* root = new Node(postorder[postIndex--]);
        int idx = mp[root->data];
        root->right = build(idx + 1, inend, postIndex, inorder, postorder, mp);
        root->left = build(instart, idx - 1, postIndex, inorder, postorder, mp);
        return root;
    }

    Node* buildTree(vector<int> inorder, vector<int> postorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
        int postIndex = postorder.size() - 1;
        return build(0, inorder.size() - 1, postIndex, inorder, postorder, mp);
    }
};
