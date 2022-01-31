class Solution {
public:
    bool Helper(TreeNode* root , long long mini, long long maxi){
        if(root == NULL)
            return true;
        if(root->val <= mini || root->val >= maxi)
            return false;
        return Helper(root->left,mini,root->val) && Helper(root->right,root->val,maxi);
    }
    bool isValidBST(TreeNode* root) {
        return Helper(root,LLONG_MIN,LLONG_MAX);
    }
};