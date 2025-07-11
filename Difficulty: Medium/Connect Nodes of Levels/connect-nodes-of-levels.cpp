/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */

class Solution {
  public:
    // Function to connect nodes at same level.
    Node* connect(Node* root) {
        // Your Code Here
        if(!root)   return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto node=q.front();
                q.pop();
                if(i!=size-1)
                node->nextRight=q.front();
                else
                node->nextRight=NULL;

                if(node->left)  q.push(node->left);
                if(node->right)  q.push(node->right);
            }
        }
        return root;
    }
};