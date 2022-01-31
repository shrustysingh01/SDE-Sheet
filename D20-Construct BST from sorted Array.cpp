class Solution {
public:
    TreeNode* createTree(vector<int>& nums,int s ,int e){
        if( s > e)
            return NULL;
        int mid = (s+e)/2;
        
        TreeNode* tree = new TreeNode(nums[mid]);
        tree->left = createTree(nums,s,mid-1);
        tree->right = createTree(nums,mid+1,e);
        return tree;    
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createTree(nums,0,nums.size()-1);
    }
};