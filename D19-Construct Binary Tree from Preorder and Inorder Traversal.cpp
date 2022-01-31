/*
Given two integer arrays preorder and inorder 
where preorder is the preorder traversal of a binary tree and 
inorder is the inorder traversal of the same tree, construct and return the binary tree.
*/

/*
Time: O(n)
Space: O(n)
Recursion + Hashmap.
Build a hashmap to store the position of each element from inorder
Call the build function on the entire array with rootIdx as 0
At each function call check whether we are in a valid range, if not return nullptr
Find the pivot / mid element using the hashmap, which is the position in inorder where our current root is at
Increment the value of rootIdx by 1
Make a new node with the pivot element from inorder
Populate the left pointer with build function result from left to pivot - 1
Populate the right pointer with build function result from pivot + 1 to right
Return the new node
*/
class Solution {
public:
     TreeNode* BuildHelper(vector<int>& preorder,int preStart,int preEnd, vector<int>& inorder,int inStart,int inEnd,unordered_map<int,int>&mp){
         
         if(preStart > preEnd || inStart > inEnd)
             return NULL;
         
         TreeNode* root = new TreeNode(preorder[preStart]);
         
         int inRoot = mp[root->val];
         int numsLeft = inRoot-inStart;
         
         root->left = BuildHelper(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,mp);
         root->right = BuildHelper(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,mp);
         
         return root;
             
     }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i = 0 ; i < inorder.size() ; i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root = BuildHelper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
};