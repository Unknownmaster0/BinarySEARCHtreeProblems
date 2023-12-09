/*
Concept -> Merge two BST and form a single BST.

Time complexiy -> O(N)  &   Space complexity -> O(number of nodes)
Approach 1 -> store the inorder traversal of the Both BST and then, join them to make a new inorder vector.
                Finally make a BST using that inorder.

Time complexity -> O(N) & Space complexity -> O(height of the tree.)
Approach 2 -> step 1 -=> make the doubly linked list of the 1st BSt
              step 2 -=> make the another doubly linked list of the 2nd BST
              step 3 -=> merge both the doubly linked list to form a new sorted list.
              step 4 -=> finally make the BST from the doubly linked list.
*/

/*
// Approach 1
void inorder(TreeNode* root, vector<int>& in)
{
    if(root == NULL)
        return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    vector<int> arr;
    inorder(root1,arr);

    vector<int>brr;
    inorder(root2,brr);

    vector<int> ans;
    ans.insert(ans.end(),arr.begin(),arr.end());
    ans.insert(ans.end(),brr.begin(),brr.end());

    sort(ans.begin(),ans.end());
    return ans;
}
*/

// Approach 2 -> 

// generate the sorted doubly linked list from the BST.
void generateList(TreeNode* root, TreeNode*& head)
{
    if(root == NULL)
        return;

    generateList(root->right,head);
    root -> right = head;
    if(head != NULL)
        head -> left = root;
    head = root;

    generateList(root->left,head);
}

TreeNode* mergelist(TreeNode* head1, TreeNode* head2)
{
    TreeNode* head = NULL;
    TreeNode* tail = NULL;

    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data < head2->data)
        {
            if(head == NULL)
            {
                head = head1;
                tail = head;
                head1 = head1 -> right;
            }
            else
            {
                tail -> right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1 -> right;
            }
        }
        else{
            if(head == NULL)
            {
                head = head2;
                tail = head;
                head2 = head2 -> right;
            }
            else
            {
                tail -> right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2 -> right;
            }
        }
    }

    while(head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1 -> right;
    }

    while(head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2 -> right;
    }

    return head;
}

// find the number of nodes.
int countNodes(TreeNode* head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head -> right;
    }
    return count;
}

TreeNode* generateBST(TreeNode* & head, int n)
{
    if(n <= 0 || head == NULL)
        return NULL;

    TreeNode* leftTree = generateBST(head, n/2);

    TreeNode* root = head;

    root -> left = leftTree;

    head = head -> right;

    root -> right = generateBST(head, n-n/2-1);
    return root;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    TreeNode* head1;
    TreeNode* head2;
    
    generateList(root1,head1);
    head1 -> left = NULL;
    generateList(root2,head2);
    head2 -> left = NULL;

    TreeNode* finalList = mergelist(head1,head2);

    int nodes = countNodes(finalList);

    return generateBST(finalList,nodes);
}