#include <iostream>
using namespace std;
/*question -> To check if any two nodes sum in the bst will equal to target or not.*/
class Node
{
public:
    int data;
    Node *left, *right;

    Node(int val)
    {
        this->data = val;
        left = right = NULL;
    }
};

/* concept -> Do the inorder traversal and store it in the vector, as we know that the inorder traversal of the bst is sorted.
            Then apply the two pointer approach on the vector and check if there exist any pair or not.*/

void inorder(Node *root, vector<int> &store)
{
    if (root == NULL)
        return;
    // left node
    inorder(root->left, store);
    // node or root
    store.push_back(root->data);
    // right node
    inorder(root->right, store);
}

bool checkSum(Node *root, int target)
{
    // do inorder traversal and store it in the vector.
    vector<int> store;
    inorder(root, store);

    // now store contains the sorted form of bst nodes.
    // now apply the two pointer approach on the store vector.
    int left = 0, right = store.size() - 1;
    while (left < right)
    {
        int sum = store[left] + store[right];
        if (sum == target)
            return true;
        else if (sum > target)
            right--;
        else
            left++;
    }
    return false;
}

int main()
{

    return 0;
}