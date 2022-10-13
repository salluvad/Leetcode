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
    ListNode* removeElements(ListNode* head, int val) {
        // two conditions to keep in mind 
        // if the node to be deleted is an internal node
        //if the node to be deleted is head 
        
        //swe strt with a dummy node / pre head
        ListNode* preHead = new ListNode(0);
        preHead->next = head;
        ListNode* prev = preHead;
        ListNode* curr = head ;
        ListNode* to_Del = NULL;
        
        while(curr!=NULL){
            if(curr->val == val){
                to_Del = curr;
                prev->next = curr->next;   // update the link
                } else prev = curr;
            curr = curr->next;
            if(to_Del != NULL){
                delete to_Del;
                to_Del = NULL;
            }
        }
        
       return  preHead->next;
        
    }
};
