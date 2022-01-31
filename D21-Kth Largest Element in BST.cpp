class Solution
{
    public:
    void BSTUtil(Node* root, int k , vector<int>& res){
        if(root == NULL)
            return;
        BSTUtil(root->left,k,res);
        res.push_back(root->data);
        BSTUtil(root->right,k,res);
    }
    
    int kthLargest(Node *root, int K)
    {
        //Your code here
        Node* cur = root;
        queue<Node*>q;
        q.push(root);
        int c = 0;
        while(!q.empty()){
           Node* node = q.front();
           c++;
           q.pop();
           if(node->left)
             q.push(node->left);
            
           if(node->right)
             q.push(node->right);
        }
         //cout<<c<<"\n";
        int k = c-K+1;
        
        vector<int> res;
        
        BSTUtil(root,k,res);
        
        return res[k-1];
    }
};