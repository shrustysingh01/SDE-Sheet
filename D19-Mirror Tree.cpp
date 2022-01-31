
/*
Given the root of two binary trees, check whether they are mirror of one another.
*/

/*
Time: O(n)
Space: O(n)
Recursion.
If both root are nullptr return true
If any one is nullptr return false
If node value of both root is equal and node -> left is mirror of node2 -> right and vice-versa return true, else false
*/

void mirror(struct Node* node) {
    // code here
    if(node == NULL)
        return;
    mirror(node->left);
    mirror(node->right);
    
    struct Node* temp = node->left;
    node->left = node->right;
    node->right = temp;
}
