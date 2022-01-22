class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next ==NULL || k == 0){
            return head;
        }
        
        int len = 1;
        
        ListNode* temp = head;
        
        while(temp->next != NULL && ++len)
            temp = temp->next;
         
        
        
        temp->next = head;
        
        if(len <= k)
            k = k%len;
        
         k = len-k;
       
        
        while(k--)
            temp = temp->next;
        
        
        head = temp->next;
        temp->next = NULL;
        
    
        
        
        return head;
        
        
        
    }
};