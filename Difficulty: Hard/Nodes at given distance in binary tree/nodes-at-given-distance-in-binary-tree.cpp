/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution {

  public:
    unordered_map<Node*,Node*> parent;
    Node* key;
    void dfs(Node* root,int target)
    {
        if(!root)   return;
        if(root->data==target)
        key=root;
        
        if(!root->left && !root->right) return;
        
        if(root->left)
        parent[root->left]=root;
        if(root->right)
        parent[root->right]=root;

        dfs(root->left,target);
        dfs(root->right,target);
    }
    vector<int> KDistanceNodes(Node* root, int target, int k) {
        // return the sorted vector of all nodes at k dist
        dfs(root,target);
        queue<Node*> q;
        q.push(key);
        unordered_map<Node*,bool> vis;
        vis[key]=true;
        
        for(int i=0;i<k;i++)
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto node=q.front();
                q.pop();
                if(node->left && !vis[node->left])
                {
                    q.push(node->left);
                    vis[node->left]=true;
                }  
                if(node->right && !vis[node->right])
                {
                    q.push(node->right);
                    vis[node->right]=true;
                } 
                if(node!=root && !vis[parent[node]])
                {
                    q.push(parent[node]);
                    vis[parent[node]]=true;
                }  
            }
        }
        vector<int> res;
        while(!q.empty())
        {
            res.push_back(q.front()->data);
            q.pop();

        }
        sort(res.begin(),res.end());
        return res;
    }
};