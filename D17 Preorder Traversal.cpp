/*
Given the root of a binary tree, return the preorder traversal of its nodes' values.
*/

/*
Time: O(n)
Space: O(n)
Recursive.
Add current root -> val to res vector 
    then solve for left subtree
    then solve for right subtree
Iterative.
Use a stack to mimic the recursion calls
*/



class Solution {
public:
     void Helper(TreeNode* root , vector<int>&v){
        if(root == NULL)
            return;
        
        v.push_back(root->val);
        Helper(root->left,v);
        Helper(root->right,v);
        
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        Helper(root,ans);
        return ans;
    }
};