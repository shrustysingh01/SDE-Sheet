class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
       ListNode* start = new ListNode();
       start->next = head;
        
        ListNode* slow = start, *fast = start;
        int count = 0;
        while(count < n){
            fast = fast->next;
            count++;
        }
        
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        
        slow->next= slow->next->next;
        
        return start->next;
    }
        
};