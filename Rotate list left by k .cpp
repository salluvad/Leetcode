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
    ListNode* rotateLeft(ListNode* head, int k) {
        
        if(k==0){
            return head;
        }
        
        int count =1 ;
        ListNode* curr = head;
        
        while(count < k and curr!=NULL){
           
            curr = curr->next;
             count++;
        }
        
        if(curr==NULL) {
            // outside the list
            return head ;   
        }
        
        ListNode* KthNode = curr;
        
        while(curr->next!=NULL){
            curr = curr->next;
        }
        
        //connect end to first
        curr->next = head;
        
        head = KthNode->next;
        
        KthNode->next = NULL;
        
        return head;
    }
};
