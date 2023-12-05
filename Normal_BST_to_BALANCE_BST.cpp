/*question link -> https://www.codingninjas.com/studio/problems/normal-bst-to-balanced-bst_920472?leftPanelTab=0&leftPanelTabValue=PROBLEM*/


/*
Concept -> We have given the normal BST, then store the inorder traversal of the 
BST, in some data structure.
Now, your question becomes make the BST from the inorder traversal.
*/

// function to store the inorder traversal of the tree.
void inorder(TreeNode<int>* root, vector<int>&store)
{
    if(root == NULL)
        return;

    inorder(root->left, store);
    store.push_back(root->data);
    inorder(root->right, store);
}

// function to create the BST from the Inorder traversal.
TreeNode<int>* createList(int start, int end, vector<int>& store)
{
    if(start > end)
        return NULL;
    
    int mid = (start + end)/2;
    TreeNode<int>* root = new TreeNode<int> (store[mid]);
    root -> left = createList(start, mid-1, store);
    root -> right = createList(mid+1,end, store);
    return root;
}

// Utility function.
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int>store;
    inorder(root,store);

    // now store contains element of the BST in sorted form.
    return createList(0,store.size()-1,store);
}
