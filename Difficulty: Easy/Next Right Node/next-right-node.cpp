/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    bool isLeaf(Node* A)
    {
        return !A->left && !A->right;
    }
    Node *nextRight(Node *root, int key) {
        // code here
        if(isLeaf(root))
        return new Node(-1);
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto node=q.front();
                q.pop();
                if(node->data==key)
                {
                    if(i!=size-1)
                    return q.front();
                    else
                    return new Node(-1);
                }
                if(node->left)  q.push(node->left);
                if(node->right)  q.push(node->right);
            }
        }
        return new Node(-1);
    }
};