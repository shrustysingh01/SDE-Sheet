class Solution {
public:
    ListNode* Middle(ListNode* fast, ListNode* slow){
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* reverse(ListNode *head){
        
        ListNode* prev = NULL, *curr = head;
        ListNode* nex;
        
        while(curr != NULL){
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;   
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL or head->next == NULL)
            return true;
        
         ListNode* fast = head, *slow = head;
         slow = Middle(fast,slow);
        
        slow->next = reverse(slow->next);
        
        slow = slow->next;
        
        while(slow != NULL){
            if(head->val != slow->val)
                return false;
            slow = slow->next;
            head = head->next;
        }
        
        return true;
    }
};