Given two integer arrays inorder and postorder 
where inorder is the inorder traversal of a binary tree 
and postorder is the postorder traversal of the same tree, construct and return the binary tree.
*/

/*
Time: O(n)
Space: O(n)
Recursion + Hashmap.
Build a hashmap to store the position of each element from inorder
Call the build function on the entire array with rootIdx as 0
At each function call check whether we are in a valid range, if not return nullptr
Find the pivot / mid element using the hashmap, which is the position in inorder where our current root is at
Decrement the value of rootIdx by 1
Make a new node with the pivot element from inorder
Populate the right pointer with build function result from pivot + 1 to right
Populate the left pointer with build function result from left to pivot - 1
Return the new node
*/
class Solution {
public:
    TreeNode* buildHelper(vector<int>& inorder,vector<int>& postorder,int inStart,int inEnd , int postStart,int postEnd,map<int,int>&mp){
        if(inStart > inEnd || postStart > postEnd)
            return NULL;
        
        TreeNode* root = new TreeNode(postorder[postEnd]);
        
        int inRoot = mp[root->val];
        int numsLeft = inRoot-inStart;
        
        root->left = buildHelper(inorder,postorder,inStart,inRoot-1,postStart,postStart+numsLeft-1,mp);
        root->right = buildHelper(inorder,postorder,inRoot+1,inEnd,postStart+numsLeft,postEnd-1,mp);
        
        return root;    
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mp;
        
        for(int i = 0 ; i < inorder.size() ; i++){
            mp[inorder[i]] = i;
        }
        
        return buildHelper(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1,mp);
    }
};