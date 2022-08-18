 void deleteNthNodeFromEnd(Node* head, int n)
    {
        Node* fast = head;
        Node* slow = head;
 
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
 
        if (fast == NULL) {
            return;
        }
 
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return;
    }
