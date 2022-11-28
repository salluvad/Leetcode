Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // maintain two sublists left and right which contains values less and more than x 
        // and connect left to right 
         ListNode* left = new ListNode();
         ListNode* right = new ListNode();
         ListNode* left_head = left;
         ListNode* right_head = right;
         ListNode* temp = head;
        while(head){
          
            if (head->val < x){
                left->next = head;
                left = left -> next;
                head = head -> next;
                left->next = NULL;
            }
            else{
                right->next = head;
                right = right -> next;
                head = head -> next;
                right -> next = NULL;
            }
        }
        left -> next = right_head -> next;

        return left_head -> next;
        
    }
    
};
