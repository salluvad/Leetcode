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
private:
    void reverse(ListNode** head_ref) {
        ListNode *prev = NULL;
        ListNode *curr = *head_ref ;
        ListNode *next;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        *head_ref = prev;
    }
    
    bool compare(ListNode*Node1 , ListNode* Node2){
        ListNode* temp1 = Node1; 
        ListNode* temp2 = Node2; 
  
    while (temp1 && temp2)
    { 
        if (temp1->val == temp2->val) 
        { 
            temp1 = temp1->next; 
            temp2 = temp2->next; 
        } 
        else
            return 0; 
    } 
  
    // Both are empty return 1
    if (temp1 == NULL && temp2 == NULL) 
        return 1; 
  
    // Will reach here when one is NULL 
    // and other is not 
    return 0;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        // O(1)  >> reverse the second half , compare two halfs anf revrse it back to construct the original list;
        
        //slow and fast pointer method to find the middle of list
        ListNode *slow_ptr = head, *fast_ptr = head; 
        ListNode *second_half, *prev_of_slow_ptr = head; 
        
         ListNode* midnode = NULL; 
        
        bool res = true ;
        
        if(head!=NULL and head->next!=NULL){
            //get the mid
             while (fast_ptr != NULL && fast_ptr->next != NULL) 
            { 
                fast_ptr = fast_ptr->next->next; 
  
                // We need previous of the slow_ptr for 
                // linked lists with odd elements
                 prev_of_slow_ptr = slow_ptr; 
                 slow_ptr = slow_ptr->next; 
             } 
            //for even size , fast pter will be null after the above steps
             if (fast_ptr != NULL)
             { 
                midnode = slow_ptr; 
               slow_ptr = slow_ptr->next; 
             } 
            //get the seocnd half 
            second_half = slow_ptr;
            
            //terminate the first half
            prev_of_slow_ptr->next = NULL; 
            
            reverse(&second_half);
            
            //compare the halfs
            res = compare(head,second_half);
            
            //revrse it back
            reverse(&second_half);
            
            if(midnode){
                prev_of_slow_ptr->next = midnode;
                midnode->next = second_half;
            } else prev_of_slow_ptr->next = seocnd_half;
            
        }
      
        return res;
    }
};
