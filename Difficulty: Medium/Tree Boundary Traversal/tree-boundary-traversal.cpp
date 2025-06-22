class Solution {
public:
    bool isLeaf(Node* node) {
        return !node->left && !node->right;
    }

    void addLeftBoundary(Node* node, vector<int>& res) {
        while (node) {
            if (!isLeaf(node)) res.push_back(node->data);
            if (node->left) node = node->left;
            else node = node->right;
        }
    }

    void addLeaves(Node* node, vector<int>& res) {
        if (!node) return;
        if (isLeaf(node)) {
            res.push_back(node->data);
            return;
        }
        addLeaves(node->left, res);
        addLeaves(node->right, res);
    }

    void addRightBoundary(Node* node, vector<int>& res) {
        vector<int> temp;
        while (node) {
            if (!isLeaf(node)) temp.push_back(node->data);
            if (node->right) node = node->right;
            else node = node->left;
        }
        reverse(temp.begin(), temp.end());
        res.insert(res.end(), temp.begin(), temp.end());
    }

    vector<int> boundaryTraversal(Node* root) {
        vector<int> res;
        if (!root) return res;
        if (!isLeaf(root)) res.push_back(root->data);

        addLeftBoundary(root->left, res);
        addLeaves(root, res);
        addRightBoundary(root->right, res);

        return res;
    }
};
