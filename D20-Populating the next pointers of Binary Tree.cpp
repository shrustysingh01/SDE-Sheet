
/*
Given a binary tree
struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.
*/

/*
Time: O(n)
Space: O(lg n)
Recursion + 3 Pointer.
Initialise three pointers curr, left and right
curr is the node in current level
left and right are the leftmost and rightmost nodes found & processed for next level
While curr is not nullptr
    if left subtree exists then
        if right exists then add curr -> left as it's next and update the right
        else initialise left and right with curr -> left
    if right subtree exists then
        if right exists then add curr -> right as it's next and update the right
        else initialise left and right with curr -> right
    update the value of curr
    if curr doesn't exist then update curr to left and update left, right with nullptr
*/


class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        queue<Node*>q;
    
        Node* cur = root;
        q.push(cur);
        
        
        while(!q.empty()){
            int s = q.size();
            
            for(int i = 0 ; i < s ; i++){
                Node* node = q.front();
                q.pop();
                if(i == s-1){
                    node->next = NULL;
                }
                else{
                    node->next = q.front();
                }
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);  
            }
        }
        
        return root;
    }
};



Node* connect(Node* root) {
    Node* curr = root;
    Node *left = nullptr, *right = nullptr;
    
    while (curr) {
        if (curr -> left) {
            if (right)
                right = right -> next = curr -> left;
            else
                left = right = curr -> left;
        }
        
        if (curr -> right) {
            if (right)
                right = right -> next = curr -> right;
            else
                left = right = curr -> right;
        }
        
        curr = curr -> next;
        if (!curr) {
            curr = left;
            left = right = nullptr;
        }
    }
    
    return root;
}