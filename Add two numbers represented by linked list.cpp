// numbers represnted in revrse order 

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //create a dummy node to store the result
        ListNode dummy(0);
        ListNode* current = &dummy;
        int carry = 0 ;
        //carry+l1->val+l2->val
        while(l1 || l2 || carry) {
        if(l1) {
            carry+=l1->val;
            l1 = l1->next;
            
        }
         if(l2) {
            carry+=l2->val;
            l2 = l2->next;
          }
        current->next = new ListNode(carry%10);
        carry = carry/10;
        current= current->next;      
        
    }
        return dummy.next;
    }
    
};
