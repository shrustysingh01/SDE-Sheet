/*
Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.
*/

/*
Time: O(n * lg n)
Space: O(n)
DFS + Hashmap.
Traverse the tree and keep adding the bottom most element found so far for the current position in a hashmap
If we come to same pos again check the height for both the elements and persist the one with greater height
NOTE: Can use level order traversal for better time complexity
*/



class Solution {
  public:
    void helper(Node *root , int level , vector<int>&ans){
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        
        q.push({root,0});
        while(!q.empty()){
            auto it = q.front();
            Node* node = it.first;
            int line = it.second;
            q.pop();
            mp[line] = node->data;
            if(node->left)
               q.push({node->left,line-1});
            
            if(node->right)
               q.push({node->right,line+1});   
               
        }
        
        for(auto x:mp){
            ans.push_back(x.second);
        }
        
        return;
    }
    
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int>ans;
        
        helper(root,0,ans);
        
        return ans;
    }
};