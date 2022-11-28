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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
		    return head;
        //divide the list into two
        ListNode* p = head->next;
        
        head->next = NULL ;
        
        while(p){
           ListNode* p_next = p->next;
           ListNode*q = head ; 
            
          if(p->val < q->val){
              p->next = q;
              head = p;
          }
          else {
              //move q to correct position 
            while (q != NULL && q->next != NULL && q->next->val <= p->val) {
				q = q->next;
             }
              //insert the node
            p->next = q->next;
			q->next = p;
          }
            //move the p node
            p = p_next;
        }
        return head;
    }
};
