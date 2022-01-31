class Solution {
public:
   
    void traversal(TreeNode* root,int d,int m,map<int, map<int, multiset<int>>> &mp){
        if(root == NULL)
            return;
        
        mp[d][m].insert(root->val);
        
        traversal(root->left,d-1,m+1,mp);
        traversal(root->right,d+1,m+1,mp);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>v;
        
        map<int, map<int, multiset<int>>> mp;
        traversal(root,0,0,mp);
        
        for(auto i:mp){
            vector<int>col;
            for(auto x:i.second){
                col.insert(col.end(), x.second.begin(), x.second.end());
            }
            v.push_back(col);
        }
         return v;
    }
   
};