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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* first;
         ListNode* second;
        
        if(head == NULL){
            return NULL;
        }
        
        first = head ;
        second  = first->next? first->next :NULL;
        while(second!=NULL){
            
            if(first->val==second->val){
                second = second->next;
                if(second == NULL){
                    delete first->next;
                    first->next = NULL;
                }
            }else {
                    
                    ListNode*temp = first->next;
                    while(temp!=second){
                        ListNode* prev = temp;
                        temp=temp->next;
                        delete prev;
                    }
                first->next = second;
             
                first=first->next;
                second = second->next;
            }
        }
        return head;
    }
};
