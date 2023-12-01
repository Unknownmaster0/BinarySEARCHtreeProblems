void inorder(Node*root, vector<int>&store, vector<int>&leaf)
{
    if(root == NULL)
        return;
        
    inorder(root->left,store,leaf);
    if(root -> left == NULL && root -> right == NULL)
    {
        // cout<<root->data<<endl;
        leaf.push_back(root->data);
    }
    else 
        store.push_back(root->data);
        
    inorder(root->right,store,leaf);
    
}
    
bool isDeadEnd(Node *root)
{
    // map<Node*, Node*> parentMap;
    // mapping(root,parentMap);
    // return solve(root, parentMap);
    
    vector<int>store;
    vector<int> leaf;
    
    inorder(root,store,leaf);
    
    // now check for each leaf it contains any x + 1 and x - 1;
    for(int i = 0; i<leaf.size(); i++)
    {
        if(leaf[i] ==  1 && find(store.begin(),store.end(),2) != store.end())
            return true;

/********   IMPORTANT CONCEPT   ******************/
/* if a node is dead node -> then BST must contains the node-1 and node+1 value both.*/                

        // find the leaf[i]-1 and and leaf[i] + 1 both in the store vector
        else if(find(store.begin(),store.end(),leaf[i]-1) != store.end() && find(store.begin(),store.end(),leaf[i]+1) != store.end())
            return true;
    }
    
    return false;
}