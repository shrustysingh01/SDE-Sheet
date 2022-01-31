
/*
Given the root of a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom.
*/

/*
Time: O(n)
Space: O(n)
Level Order Traversal.
Traverse the tree level by level and at each level add the last node for that level.
During level traversal first go to right node then left node.
NOTE: Can be done using DFS also.
*/

void traverse(TreeNode* root,int level,int &maxlevel,vector<int>&v){
        if(root == NULL)
            return;
        
        if(maxlevel < level){
             v.push_back(root->val);
            maxlevel = level;
        }
        traverse(root->right,level+1,maxlevel,v);
        traverse(root->left,level+1,maxlevel,v);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
        int maxlevel = -1;
        traverse(root,0,maxlevel,v);
        return v;
    }