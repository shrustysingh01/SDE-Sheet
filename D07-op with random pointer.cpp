class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;
  
        Node* curr = head;
        
     while(curr != NULL){
         Node* temp = new Node(curr->val);
         temp->next = curr->next;
         curr->next = temp;
         curr = curr->next->next;
     }  
        
     curr = head;

     while(curr != NULL){
        if(curr->random != NULL){
            curr->next->random = curr->random->next;
         }
        curr = curr->next->next;
    }
 

        Node* real = head;
        Node* copy = real->next;
        Node* temp = copy;
        
        while(real && copy){
            if(real->next){
                real->next = real->next->next;
            }
            if(copy->next){
                copy->next = copy->next->next;
            }
            real = real->next;
            copy = copy->next;
        }
      return temp;
    }
};