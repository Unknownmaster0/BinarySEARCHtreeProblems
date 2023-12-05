/*You have given the preorder traversal of the tree, now you need to return the BST.*/

/*concept ->
Approach 1 -> As we know the inorder of the BST is sorted and given preorder array of BST.
            So, simply sort the preorder array given. Now, this will become the inorder of the BST.
            Now, the question becomes form the BST from the inorder traversal. which is easy task.

            given inorder -> step 1 -> find the mid of the inorder array.
                            step 2 -> then make the root to the mid element.
                            step 3 -> root -> left ke liye call maar do left array before mid
                            step 4 -> root -> right ke liye call maar do right array after mid.
                            finally return root.

Approach 2 -> Use the normal BST insert node function property.

Approach 3 -> use the preorder technique of the BST.

*/
// Approach 1
BinaryTreeNode<int> *createList(int start, int end, vector<int> &inorder)
{
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(inorder[mid]);
    root->left = createList(start, mid - 1, inorder);
    root->right = createList(mid + 1, end, inorder);
    return root;
}

BinaryTreeNode<int> *preorderToBST(vector<int> &preorder)
{
    sort(preorder.begin(), preorder.end());

    // now we have the inorder traversal of the BST which is in sorted form.
    // Make the BST using this inorder traversal.
    return createList(0, preorder.size() - 1, preorder);
}

// Approach 3
BinaryTreeNode<int> *createList(int mini, int maxi, vector<int> &preorder, int &idx)
{
    if (idx >= preorder.size())
        return NULL;

    if (preorder[idx] > mini && preorder[idx] < maxi)
    {
        BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preorder[idx++]);
        root->left = createList(mini, root->data, preorder, idx);
        root->right = createList(root->data, maxi, preorder, idx);
        return root;
    }
    return NULL;
}

BinaryTreeNode<int> *preorderToBST(vector<int> &preorder)
{
    // method 2 -> using the propery of the preorder traversal and the range property.
    int maxi = INT_MAX;
    int mini = INT_MIN;
    int i = 0;
    return createList(mini, maxi, preorder, i);
}