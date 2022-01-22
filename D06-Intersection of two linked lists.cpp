class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = 1,l2 =1;
        ListNode* a = headA;
        ListNode* b = headB;
        
        while(a != b){
            a = a == NULL ? headA: a = a->next;
            b = b == NULL ? headB: b = b->next;
        }
        return a;
    }
};