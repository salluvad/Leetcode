class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        // Initialize current, previous and next pointers
        ListNode* current = head;
        ListNode *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
        
        return head;
    
    }
};
