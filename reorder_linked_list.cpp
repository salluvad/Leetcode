/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …

*/



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
    void reorderList(ListNode* head) {
       // three steps
        //split the list>>>>rverse the seocnd half >>> merge two lists
        
        //find the mid using slow and fast method
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* second = slow->next;
        slow->next= NULL;  
        ListNode* first = head;
        
        ///step 2 , reverse the second half
        
        ListNode* curr= second;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr=next;
        }
        second = prev;   // prev will the new head after rev
        
        //step 3 ,merge first and secondlist
        ListNode* preHead = new ListNode(-1);
         prev = preHead;
        
        while(first and second){
            prev->next = first;
            first= first->next;
            prev = prev->next;
            
            prev->next = second;
            second= second->next;
            prev = prev->next;
        }
        
        prev->next = (first==NULL)?second:first;
    }
};
