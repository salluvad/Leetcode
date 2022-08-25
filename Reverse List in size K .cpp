1. iterative  o{1) space
2.stack based o(k)



/**.  check TAKE you forward video for walkthrough.  https://www.youtube.com/watch?v=Of0HPkk3JgI
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
    ListNode* reverseKGroup(ListNode* head, int k) {      
    const int length = getLength(head);
    ListNode dummy(0, head);
    ListNode* prev = &dummy;
    ListNode* curr = head;

    for (int i = 0; i < length / k; ++i) {
      for (int j = 0; j < k - 1; ++j) {
        ListNode* next = curr->next;
        curr->next = next->next;
        next->next = prev->next;
        prev->next = next;
      }
      prev = curr;
      curr = curr->next;
    }

    return dummy.next;
    
       
}
    
private:
  int getLength(ListNode* head) {
        int length = 0;
        for (ListNode* curr = head; curr!=NULL; curr = curr->next)
              ++length;
        return length;
  }
};


//simple recursive/stack based 


struct Node* Reverse(struct Node* head, int k)
{
    // Create a stack of Node*
    stack<Node*> mystack;
    struct Node* current = head;
    struct Node* prev = NULL;
 
    while (current != NULL) {
 
        // Terminate the loop whichever comes first
        // either current == NULL or count >= k
        int count = 0;
        while (current != NULL && count < k) {
            mystack.push(current);
            current = current->next;
            count++;
        }
 
        // Now pop the elements of stack one by one
        while (mystack.size() > 0) {
 
            // If final list has not been started yet.
            if (prev == NULL) {
                prev = mystack.top();
                head = prev;
                mystack.pop();
            } else {
                prev->next = mystack.top();
                prev = prev->next;
                mystack.pop();
            }
        }
    }
 
    // Next of last element will point to NULL.
    prev->next = NULL;
 
    return head;
}
