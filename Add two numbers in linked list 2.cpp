//You are given two non-empty linked lists representing two non-negative integers. 
//The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

//by reversing the lists
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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev= curr;
            curr = next;
        }
        head = prev;
        return head;
        
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1 = reverse(l1);
        ListNode* head2 = reverse(l2);
        
        ListNode *res = NULL;
        int carry = 0 ;
        
        
        while(head1!=NULL ||  head2 !=NULL){
            int x1 = head1!=NULL ? head1->val:0;
            int x2 = head2!=NULL ? head2->val:0;
            
            int val = (carry+x1+x2)%10;
            
            carry = (carry+x1+x2)/10;
            
            
            ListNode* curr = new ListNode(val);
            curr->next = res;
            res = curr;
            
            head1=(head1!=NULL)?head1->next:0;
            head2=(head2!=NULL)?head2->next:0;
            
        }
        
        if(carry!=0){
         
            ListNode* curr = new ListNode(carry);
            curr->next = res;
            res = curr ;
        }
        
        return res;
        
    }
};
