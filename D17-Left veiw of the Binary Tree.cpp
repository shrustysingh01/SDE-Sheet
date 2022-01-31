void helper(Node * root , int level , vector<int>&ans){
    if(root == NULL)
       return;
       
    if(ans.size() == level){
        ans.push_back(root->data);
    }   
    
    helper(root->left,level+1,ans);
    helper(root->right,level+1,ans);
}

vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>ans;
   int level = 0;
   if(root == NULL)
      return ans;
   helper(root,level,ans);
   return ans;
}