/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution {
  public:
    // Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root) {
        // Your Code here
        vector<int> ans;
        if(!root)   return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            int right;
            for(int i=0;i<size;i++)
            {
                auto node=q.front();
                q.pop();
                right=node->data;
                if(node->left)  
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }   
            }
            ans.push_back(right);
        }
        return ans;
    }
};