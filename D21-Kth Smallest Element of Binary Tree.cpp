class Solution {
public:
    
    TreeNode* smallest(TreeNode* root,int &count,int k){
        if(!root)
            return NULL;
        
        TreeNode* left = smallest(root->left,count,k);
        
        if(left!=NULL)
            return left;
        
        count++;
        
        if(count==k)
            return root;
        
        return smallest(root->right,count,k);
    }
    
    
    int kthSmallest(TreeNode* root, int k) {
        
        int count =0;
        
        TreeNode* p = smallest(root,count,k);
        
        if(p ==NULL)
            return 0;
        else 
            return p->val;
        
    }
};