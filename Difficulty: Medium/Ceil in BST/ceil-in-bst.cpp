/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};  */

int findCeil(Node* root, int input) {
    // Your code here
    int cei=-1;
    Node* temp=root;
    while(temp)
    {
        if(temp->data==input)
        return input;
        else if(temp->data>input)
        {
            cei=temp->data;
            temp=temp->left;
        }
        else
        temp=temp->right;
    }
    return cei;
}