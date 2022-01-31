class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        int ans = 0;
        if(root == NULL)
            return 0;
        q.push({root,0});
        
        while(!q.empty()){
            int s = q.size();
            int mini = q.front().second;
            int first, last;
            for(int i = 0 ; i < s ; i++){
                TreeNode* node = q.front().first;
                int curr_id = q.front().second - mini;
                q.pop();
                
                if(i == 0)
                    first = curr_id;
                if(i == s-1)
                    last = curr_id;
                if(node->left)
                    q.push({node->left,2*curr_id+1});
                
                if(node->right)
                    q.push({node->right,2*curr_id+2}); 
            }
            ans = max(ans, last-first+1);
        }
        
        return ans;
    }
};
