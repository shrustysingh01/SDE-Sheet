class Solution {
public:
    TreeNode* BSTUtil(vector<int>& A, int &i, int bound){
        if(i == A.size() || A[i] > bound) 
            return NULL;
        
        TreeNode* root = new TreeNode(A[i]);
        i++;
        root->left = BSTUtil(A,i,root->val);
        root->right = BSTUtil(A,i,bound);
        
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return BSTUtil(preorder,i,INT_MAX);
    }
};