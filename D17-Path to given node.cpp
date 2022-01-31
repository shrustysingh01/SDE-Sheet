bool getpath(TreeNode* root,vector<int>& arr, int B){
     if(!root)
        return false;

    arr.push_back(root->val);

    if(root->val == B)
       return true;

    if(getpath(root->left,arr,B) || getpath(root->right,arr,B))
       return true;

    arr.pop_back();

    return false;     

 }
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>arr;
    if(A == NULL)
       return arr;

    getpath(A,arr,B);   

    return arr;
}
