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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head or left==right){
            return head;
        }
        ListNode* dummy = new ListNode(0), *prev = dummy, *curr,*next;
        dummy->next = head;
        for (int i = 0; i < left - 1; i++){
                prev = prev->next;
                cout << "prev" <<prev->val<< endl;
        }
        
        curr = prev->next;
        cout << curr->val << endl;
        next = curr->next;
        cout << next->val << endl;
       
       for(int i=0;i<right-left;i++) {      
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = curr->next;
        }
        
        return dummy->next;
    }
};
