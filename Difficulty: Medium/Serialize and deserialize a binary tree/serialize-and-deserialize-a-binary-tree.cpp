/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution {
  public:
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) {
        // Your code here
        vector<int> data;
        if(!root)
        return data;
        queue<Node*> q;
        q.push(root);
        data.push_back(root->data);
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto node=q.front();
                q.pop();
                if(node->left)
                {
                    q.push(node->left);
                    data.push_back(node->left->data);
                }
                else
                data.push_back(-1);
                if(node->right)
                {
                    q.push(node->right);
                    data.push_back(node->right->data);
                }
                else
                data.push_back(-1);
            }
        }
        return data;
    }

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &arr) {
        int n=arr.size();
        if(n==0)
        return NULL;
        int i=0;
        Node* root=new Node(arr[i++]);
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            if(arr[i]!=-1)
            {
                node->left=new Node(arr[i]);
                q.push(node->left);
            }
            i++;
            if(i<n && arr[i]!=-1)
            {
                node->right=new Node(arr[i]);
                q.push(node->right);
            }
            i++;
        }
        return root;
    }
};