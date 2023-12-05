#include<iostream>
using namespace std;

/*question link -> https://www.codingninjas.com/studio/problems/flatten-bst-to-a-sorted-list_1169459?leftPanelTab=0&leftPanelTabValue=SUBMISSION*/

/*concept -> do the inorder traversal to store the sorted list of the BST to data structure such as vector<int>store.
Then iterate over the vector to make the data of the vector into list.
*/

/* ************** WHAT IS THE PROBLEM IN THIS PLEASE DO FIND ****************
void inorder(TreeNode<int>* root, vector<TreeNode<int>*>&store)
{
    if(root == NULL)
        return;

    inorder(root->left,store);
    store.push_back(root);
    inorder(root->right,store);
}


TreeNode<int>* flatten(TreeNode<int>* root)
{
    
    vector<TreeNode<int>*>store;
    inorder(root,store);

    TreeNode<int>* head = store[0];
    TreeNode<int>* temp = head;
    for (int i = 1; i < store.size(); ++i)
    {
        temp->left = NULL; // Remove this line to preserve left child links
        temp->right = store[i];
        temp = temp->right;
    }

    temp -> left = NULL;
    temp -> right = NULL;
    
    return head;
}
*/

void inorder(TreeNode<int>* root, vector<int>&store)
{
    if(root == NULL)
        return;

    inorder(root->left,store);
    store.push_back(root->data);
    inorder(root->right,store);
}
TreeNode<int> *flatten(TreeNode<int> *root) 
{
    vector<int>store;
    inorder(root,store);

    TreeNode<int>* head = new TreeNode<int>(store[0]);
    TreeNode<int>* temp = head;

    for(int i = 1; i<store.size(); i++)
    {
        TreeNode<int>* newNode = new TreeNode<int>(store[i]);
        temp -> left = NULL;
        temp -> right = newNode;
        temp = newNode;
    }

    temp -> left = NULL;
    temp -> right = NULL;

    return head;

}

int main()
{
    
    return 0;
}