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
    void merge_sort(ListNode** head){
        
        ListNode*curr = *head ;
        if(curr == NULL or curr->next == NULL){
            return;
        }
        ListNode* first;
        ListNode* second;
        
        //find mid
        find_mid(curr,&first,&second);
        
        merge_sort(&first);
        merge_sort(&second);
        *head = merge(first,second);
       
    }
    //find the mid of the list
    void find_mid(ListNode* curr , ListNode** first,ListNode** second){
        ListNode* slow = curr;
        ListNode* fast = curr->next;
        while(slow and fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        *first = curr;
        *second = slow->next;
        slow->next = NULL;
    }
    
    ListNode* merge(ListNode* first, ListNode* second){
        ListNode* answer = NULL;        
        if(first == NULL) 
        {
          return second; 
        }
        
        if(second == NULL) 
        {
           return first; 
        }
           
        if(first -> val <= second -> val) 
        {
            answer = first;
            answer -> next = merge(first -> next, second); 
        }
        else 
        {
            answer = second;
            answer -> next = merge(first, second -> next); 
        }
        
        return answer; 
    }
    ListNode* sortList(ListNode* head) {
        // using merge sort
        merge_sort(&head);
        return head;
    }
};
