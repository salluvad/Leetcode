Node* deleteNthNodeFromEnd(Node* head, int n)
    {
        Node* fast = head;
        Node* slow = head;
 
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
  // when n is the same as the length of the list, which would make the first node the target node, 
  //and thus make it impossible to find the node before the target node. If that's the case, however, 
  //we can just return head.next without needing to stitch together the two sides of the target node.
        if (fast == NULL) {
            return head->next;
        }
 
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
