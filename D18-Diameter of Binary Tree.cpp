
/*
Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
This path may or may not pass through the root.
The length of a path between two nodes is represented by the number of edges between them.
*/

/*
Time: O(n)
Space: O(n)
DFS + DP.
*/

class Solution {
public:
    int helper(TreeNode* root,int &maxi){
        if(root == NULL)
            return 0;
        int h1 = helper(root->left,maxi);
        int h2 = helper(root->right,maxi);
        maxi = max(maxi,h1+h2);
        return 1 + max(h1,h2);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        int Diameter = 0;
        helper(root,Diameter);
        return Diameter;
    }
};