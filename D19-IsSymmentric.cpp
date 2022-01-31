/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
*/

/*
Time: O(n)
Space: O(n)
Recursion.
Use helper function which checks whether the two given nodes are of mirrored tree
If both root are nullptr return true
If any one is nullptr return false
If node value of both root is equal and node -> left is mirror of node2 -> right and vice-versa return true, else false
*/

class Solution {
public:
    bool isSame(TreeNode* l, TreeNode* r){
        if(l==NULL || r== NULL)
            return l==r;
        
        if(l->val != r->val)
            return false;
        
        return (l->val == r->val)&& isSame(l->left,r->right) &&isSame(l->right,r->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
       
        return isSame(root->left,root->right);
    }
};