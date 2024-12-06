//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

Node* inputTree(){
    string treeString;
    getline(cin,treeString);
    Node* root = buildTree(treeString);
    return root;
}
void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Helper function to check if a node is a leaf node
    bool isLeaf(Node* root) {
        return root && !root->left && !root->right;
    }
    
    // Recursive function to find all paths
    void findPaths(Node* root, vector<vector<int>>& result, vector<int>& currentPath) {
        if (!root) return; // Base case: null node
        
        // Add the current node to the path
        currentPath.push_back(root->data);
        
        // If it's a leaf node, store the current path
        if (isLeaf(root)) {
            result.push_back(currentPath);
        } else {
            // Recur for left and right subtrees
            if (root->left) findPaths(root->left, result, currentPath);
            if (root->right) findPaths(root->right, result, currentPath);
        }
        
        // Backtrack to explore other paths
        currentPath.pop_back();
    }
    
    // Function to return all root-to-leaf paths
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> result;
        vector<int> currentPath;
        
        // Edge case: empty tree
        if (!root) return result;
        
        // Find all paths
        findPaths(root, result, currentPath);
        return result;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        Node* root = inputTree();
        
        Solution obj;
        vector<vector<int>> res = obj.Paths(root);
        
        Matrix::print(res);
        
    
cout << "~" << "\n";
}
}

// } Driver Code Ends