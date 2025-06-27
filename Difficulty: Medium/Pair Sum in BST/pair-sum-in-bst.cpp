class Solution {
    stack<Node*> s1, s2;

    void pushLeft(Node* node) {
        while (node) {
            s1.push(node);
            node = node->left;
        }
    }

    void pushRight(Node* node) {
        while (node) {
            s2.push(node);
            node = node->right;
        }
    }

  public:
    bool findTarget(Node *root, int target) {
        if (!root) return false;
        pushLeft(root);
        pushRight(root);
        
        while (!s1.empty() && !s2.empty() && s1.top() != s2.top()) {
            int leftVal = s1.top()->data;
            int rightVal = s2.top()->data;
            
            if (leftVal + rightVal == target) return true;
            else if (leftVal + rightVal < target) {
                Node* node = s1.top(); s1.pop();
                pushLeft(node->right);
            } else {
                Node* node = s2.top(); s2.pop();
                pushRight(node->left);
            }
        }
        return false;
    }
};
