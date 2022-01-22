class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l1 = list1 , *l2 = list2;
        ListNode* newhead = new ListNode(0);
        ListNode* head = newhead;
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                 head->next = new ListNode(l1->val);
                 l1 = l1->next;
                 head = head->next;
            }
            else{
                 head->next = new ListNode(l2->val);
                 l2 = l2->next;
                 head = head->next;
            }
        }
        
        while(l1 != NULL){
            head->next = new ListNode(l1->val);
            l1 = l1->next;
            head = head->next;
        }
        
        while(l2 != NULL){
           head->next = new ListNode(l2->val);
           l2 = l2->next;
            head = head->next;
        }
        
        return newhead->next;
        
    }
};