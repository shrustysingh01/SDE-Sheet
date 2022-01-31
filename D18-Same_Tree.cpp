/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
*/

/*
Time: O(n)
Space: O(n)
Recursion.
If both nodes are nullptr return true
If any one is nullptr return false
If val at both nodes is equal and left subtree of both are equal and right subtree of both are equal
    then return true, else false
*/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if( p== NULL && q == NULL)
            return true;
    
        if(!p || !q)
            return false;
        
        return (p->val == q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};