class BSTIterator{
    public:
    stack<TreeNode*>st;
    bool reverse = false;
    BSTIterator(TreeNode* root,bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }
    
    void pushAll(TreeNode* root){
        while(root != NULL){
            st.push(root);
            if(!reverse){
               root= root->left;
            }
            else{
                root = root->right;
            }
        }
    }
    
    int next(){
        TreeNode* node = st.top();
        st.pop();
        
        if(!reverse){
            pushAll(node->right);
        }
        else{
            pushAll(node->left);
        }
        return node->val;  
    }
    
    
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;
        
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        
        int i = l.next();
        int j = r.next();
        
        while( i < j){
            if(i+ j == k)
                return true;
            else if((i + j) < k){
                i = l.next();
            }
            else {
                 j = r.next();
            }
        }
        
        return false;
    }
};