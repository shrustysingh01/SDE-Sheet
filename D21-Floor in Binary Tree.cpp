int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    TreeNode<int> *cur = root;
        int floor = -1;
        while(cur != NULL){
            if(cur->val == X){
                floor = cur->val;
                return floor;
            }
            else if(cur->val < X){
                floor = cur->val;
                cur = cur->right;
            }
            else{
                cur = cur->left;
            }
        }
        
        return floor;
        
        
}