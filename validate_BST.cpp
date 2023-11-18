#include<iostream>
#include<limits.h>
using namespace std;

class Node{
    public:
        int data;
        Node*left;
        Node* right;

    Node(int val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

};

// time complexity -> O(N)
// space complexity -> O(Height)

bool isBST(Node * root, int mini, int maxi)
{
    if(root == NULL)
        return true;

// if the node is satifying this condition then only the node is consider under BST.
    if(root -> data >= mini && root -> data <= maxi)
    {
        // then check its right and left child;
        bool left = isBST(root->left, mini, root -> data);
        bool right = isBST(root->right, root->data,  maxi);

        return (left && right);
    }

    return false;
}

bool validateBST(Node *root) {
    int maxi = INT_MAX;
    int mini = INT_MIN;

    return isBST(root, mini, maxi);
}

int main()
{
    
    return 0;
}