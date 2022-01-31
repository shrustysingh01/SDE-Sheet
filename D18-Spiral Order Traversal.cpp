/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
(i.e., from left to right, then right to left for the next level and alternate between).
*/

/*
Time: O(n)
Space: O(n)
Level Order Traversal + Reverse level nodes.
*/


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL)
            return ans;
        queue<TreeNode*>q;
        q.push(root);
        int x = 0;
        
        while(!q.empty()){
            int Size = q.size();
            vector<int>v;
            x++;
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
            if(x%2 == 0)
                reverse(v.begin(),v.end());
            ans.push_back(v);
        }
      return ans;  
    }
};