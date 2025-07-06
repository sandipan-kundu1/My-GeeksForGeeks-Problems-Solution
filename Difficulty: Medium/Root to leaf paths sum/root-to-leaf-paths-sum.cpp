class Solution {
  public:
    int dfs(Node* root, int currSum) {
        if (!root) return 0;

        currSum = currSum * 10 + root->data;

        // If leaf node, return the current number
        if (!root->left && !root->right)
            return currSum;

        // Otherwise, sum from left and right
        int leftSum = dfs(root->left, currSum);
        int rightSum = dfs(root->right, currSum);

        return leftSum + rightSum;
    }

    int treePathsSum(Node *root) {
        return dfs(root, 0);
    }
};
