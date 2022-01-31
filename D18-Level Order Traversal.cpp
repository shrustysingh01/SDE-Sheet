class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL)
            return ans;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int Size = q.size();
            vector<int>v;
            while(Size--){
                TreeNode* node = q.front();
                v.push_back(node->val);
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            ans.push_back(v);
        }
      return ans;  
    }
};