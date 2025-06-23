/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        vector<vector<int>> ans;
        if(!root)   return ans;
        
        map<int,map<int,vector<int>>> nodes;
        queue<pair<Node*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            auto node=p.first;
            int col=p.second.first,level=p.second.second;
            nodes[col][level].push_back(node->data);
            if(node->left)
            q.push({node->left,{col-1,level+1}});
            if(node->right)
            q.push({node->right,{col+1,level+1}});
        }
        
        for(auto it:nodes)
        {
            vector<int> line;
            for(auto lvl:it.second)
            {
                for(auto val:lvl.second)
                line.push_back(val);
            }
            ans.push_back(line);
        }
        return ans;
    }
};