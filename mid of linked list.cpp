class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        ListNode* slow= head;
        ListNode* fast= head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
};
