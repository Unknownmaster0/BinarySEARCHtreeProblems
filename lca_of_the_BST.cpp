#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left, * right;

    Node(int val){
        this -> data = val;
        left = right = NULL;
    }

};

/*concpt -> 
    simply we need to think of two condition 
    1. if d1 and d2 both are smaller than root node -> it means we need to go to the left subtree to find our lca
    2. if d1 and d2 both are greater than root node -> it means we need to go to the right subtree to find our lca
    3. else you have reached to your LCA node return root.
*/

// d1 -> data 1
// d2 -> data 2
// recursive way to find the LCA
// Time complexity -> O(number of nodes)
// space complexity -> O(auxillary stack space || number of nodes)
Node* LCA(Node* root, Node* d1, Node* d2){
    if(root == NULL)    return NULL;

// when root data is greater than both d1 and d2
    if(root -> data > d1->data && root -> data > d2->data)
        return LCA(root->left, d1, d2);

// when root data is smaller than both d1 and d2
    if(root->data < d1->data && root->data < d2->data)
        return LCA(root->right , d1,d2);

    // else in any condition you must have reached to the lca node
    return root;
}

// now iterative way.
// Time complexity -> O(number of nodes)
// space complexity -> O(1) constant space.
Node* LCA(Node* root, Node* d1, Node* d2){

    while(root){
    // when root data is greater than both d1 and d2
        if(root -> data > d1->data && root -> data > d2->data)
            root = root -> left;

    // when root data is smaller than both d1 and d2
        else if(root->data < d1->data && root->data < d2->data)
            root = root -> right;

        // else in any condition you must have reached to the lca node
        else
            return root;
    }
}


int main()
{
    
    return 0;
}