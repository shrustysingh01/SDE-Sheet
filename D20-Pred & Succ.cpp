void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

   Node* root1 = root;
// Your code goes here
    while(root1 != NULL){
        if(key >= root1->key){
            root1 = root1->right;
        }
        else{
            suc = root1;
            root1 = root1->left;
        }
    }
     root1 = root;
    while(root1 != NULL){
        if(key <= root1->key){
            root1 = root1->left;
        }
        else{
            pre = root1;
            root1 = root1->right;
        }
    }


}