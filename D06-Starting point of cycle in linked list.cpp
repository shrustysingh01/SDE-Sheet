class Solution {
public:
    bool isCycle(ListNode *head){
        
        ListNode* slow = head, *fast = head;
        while(fast!= NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
        
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        bool flag = false;
        
        if(head == NULL or head->next == NULL)
            return NULL;
        
        
       if(isCycle(head) == false){
           return NULL;
       }
        
        slow = head, fast = head;
        
        do{
            fast = fast->next->next;
            slow = slow->next;
        }while(fast != slow);
        
        slow = head;
        
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};