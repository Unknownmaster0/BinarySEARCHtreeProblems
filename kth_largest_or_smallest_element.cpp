#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

/* concept -> if the root is null then simply return the NULL.
        // now go to the left part.
        // if the left part is returning the NULL, then don't do anything. but if the left part is not null
        // then return the left part.

    Time complexity -> O(Nodes)
    space complexity -> O(space taken by recusive stack[Height of tree])
    */
Node *inorder(Node *root, int k, int &count)
{
    if (root == NULL)
        return NULL;

    // left part.
    Node *left = inorder(root->left, k, count);
    if (left != NULL)
    {
        cout << "i am in the left part if statement." << endl;
        return left;
    }

    // processing the node.
    count++;
    if (count == k)
    {
        cout << "root -> " << root->data << endl;
        cout << "count -> " << count << endl;
        return root;
    }

    // right part.
    return inorder(root->right, k, count);
}
int kthSmallest(Node *root, int k)
{
    // traverse the tree in inorder fashion.
    int count = 0;
    Node *node = inorder(root, k, count);
    if (node)
        return node->data;
    return -1;
}
/* time complexiy -> O(Nodes)
space complexity -> O(H) [for recursive call stack] + O(Nodes) [for vector.]
void inorder(Node* root, vector<int> &store)
{
    if(root == NULL){
        return;
    }
    inorder(root->left,store);
    store.push_back(root->data);
    inorder(root->right,store);
}

int kthSmallest(Node* root, int k) {
    vector<int>store;
    inorder(root, store);
    if(store.size() < k)
        return -1;
    return store[k-1];
}
*/

int main()
{

    return 0;
}