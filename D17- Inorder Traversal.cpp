
/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.
*/

/*
Time: O(n)
Space: O(n)
Recursive.
Solve for left subtree 
	then add current root -> val to res vector
	then solve for right subtree
Iterative.
Use a stack to mimic the recursion calls
*/


class Solution {
public:
    void Helper(TreeNode* root , vector<int>&v){
        if(root == NULL)
            return;
        
        Helper(root->left,v);
        v.push_back(root->val);
        Helper(root->right,v);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        Helper(root,ans);
        return ans;
    }
};