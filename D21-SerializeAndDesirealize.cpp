class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "";
        string ans = "";
        
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL){
                ans.append("#,");
            }
            else{
                ans.append(to_string(node->val) + ',');
            }
            
            if(node != NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
        //cout<<ans<<'\n';
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       if(data == "")
           return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            getline(s,str,',');
            if(str == "#"){
                node->left = NULL;
            }
            else{
                TreeNode* left = new TreeNode(stoi(str));
                node->left = left;
                q.push(left);
            }
            
            getline(s,str,',');
            if(str == "#"){
                node->right = NULL;
            }
            else{
                TreeNode* right = new TreeNode(stoi(str));
                node->right = right;
                q.push(right);
            }
            
        }
        
        return root;
    }
};
