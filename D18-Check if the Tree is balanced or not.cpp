
/*
Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as:
a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
*/

/*
Time: O(n)
Space: O(n)
Bottom - up recursion.
Empty case is considered as true
Write the function to find the height / depth of a binary tree 
    and at each step check whether it is height balanced or not
Final answer would be whether the left and right child are height balanced 
    and difference between the two heights is less than 2
*/

class Solution {
public:
    int flag = 0;
    int height(TreeNode* root){
        if(root == NULL)
            return 0;
        int l = height(root->left);
        int h = height(root->right);
        
        if(abs(h-l) >1)
            flag = 1;
        
        return 1 + max(l,h);
    }
    
    bool isBalanced(TreeNode* root) {
        int h = height(root);
        
        if(flag == 1)
            return false;
        return true;
    }
};