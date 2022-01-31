
/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
According to the definition of LCA on Wikipedia: 
“The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has 
both p and q as descendants (where we allow a node to be a descendant of itself).”
*/

/*
Time: O(n)
Space: O(n)
Recursion.
If a subtree is empty or doesn't have p & q return nullptr from that subtree
If left subtree returns nullptr then answer is from right subtree
If right subtree return nullptr then answer is from left subtree
Else answer is current root
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL or root == p or root == q)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        
        if(left == NULL)
            return right;
        else if(right == NULL)
            return left;
        else
            return root;
        
    }
};