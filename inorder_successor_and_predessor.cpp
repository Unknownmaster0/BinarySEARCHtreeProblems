#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left, *right;
    
};

pair<int, int> predecessorSuccessor(Node *root, int key) {
    Node* temp = root;
    int succ = -1, pred = -1;
/* concept -> if the root -> data is greater than the key value, it means my key is present in the left subtree.
            And when we see the Inorder traversal of the BST then it came to know that, greater number is the successor of the previous number.
            hence form this we can say that
            if the root -> data > key, it means the root may be the successor of the key.
            
            similarly if the root -> data < key , it means that the root is predecessor of the key.*/

    while(temp != NULL){
        if(temp -> data > key){
            succ = temp -> data;
            temp = temp -> left;
        }
        else{
            temp = temp -> right;
        }
    }

    while(root != NULL){
        if(root -> data >= key){
            root = root -> left;
        }
        else{
            pred = root -> data;
            root = root -> right;
        }
    }

    return {pred, succ};
}

int main()
{
    
    return 0;
}