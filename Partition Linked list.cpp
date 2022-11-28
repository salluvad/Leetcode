Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // maintain two sublists left and right which contains values less and more than x 
        // and connect left to right 
         ListNode* left = new ListNode();
         ListNode* right = new ListNode();
         ListNode* new_head = left;
         ListNode* merge_point = right;
         ListNode* temp = head;
        while(temp){
            if(temp->val<x){
                left->next = new ListNode(temp->val);
                left = left->next;
                
            } else {
                right->next = new ListNode(temp->val);
                right = right->next;
               
            }
             temp = temp->next;
        }
        left->next = merge_point->next;
        
        return  new_head->next;
        
    }
    
};
