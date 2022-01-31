/*
Given a binary tree, print the top view from left to right.
A node is included in top view if it can be seen when we look at the tree from top.
*/

/*
Time: O(n * lg n)
Space: O(n)
DFS + Hashmap.
Traverse the tree and keep adding the top most element found so far for the current position in a hashmap
If we come to same pos again check the height for both the elements and persist the one with lesser height
NOTE: Can use level order traversal for better time complexity
*/


class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        vector<int>ans;
        
        q.push({root,0});
        int level = 0;
        
        while(!q.empty()){
            
            auto it = q.front();
            int line = it.second;
            Node* node = it.first;
            q.pop();  
            
            if(mp.find(line) == mp.end())
                mp[line] = node->data;
                
            if(node->left)
               q.push({node->left,line-1});
               
            if(node->right)
               q.push({node->right,line+1});
               
             
        }
        
        
        for(auto x : mp){
            ans.push_back(x.second);
        }
        
        return ans;
    }

};
