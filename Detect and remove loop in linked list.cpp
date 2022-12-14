This method is also dependent on Floyd’s Cycle detection algorithm.
Detect Loop using Floyd’s Cycle detection algorithm and get the pointer to a loop node.
Count the number of nodes in the loop. Let the count be k.
Fix one pointer to the head and another to a kth node from the head.
Move both pointers at the same pace, they will meet at the loop starting node.
Get a pointer to the last node of the loop and make the next of it NULL.
  
  
  int detectAndRemoveLoop(struct Node* list)
{
    struct Node *slow_p = list, *fast_p = list;
  
    // Iterate and find if loop exists or not
    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
  
        /* If slow_p and fast_p meet at some point then there
           is a loop */
        if (slow_p == fast_p) {
            removeLoop(slow_p, list);
  
            /* Return 1 to indicate that loop is found */
            return 1;
        }
    }
  
    /* Return 0 to indicate that there is no loop*/
    return 0;
}
void removeLoop(struct Node* loop_node, struct Node* head)
{
    struct Node* ptr1 = loop_node;
    struct Node* ptr2 = loop_node;
  
    // Count the number of nodes in loop
    unsigned int k = 1, i;
    while (ptr1->next != ptr2) {
        ptr1 = ptr1->next;
        k++;
    }
  
    // Fix one pointer to head
    ptr1 = head;
  
    // And the other pointer to k nodes after head
    ptr2 = head;
    for (i = 0; i < k; i++)
        ptr2 = ptr2->next;
  
    /*  Move both pointers at the same pace,
      they will meet at loop starting node */
    while (ptr2 != ptr1) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
  
    // Get pointer to the last node
    while (ptr2->next != ptr1)
        ptr2 = ptr2->next;
  
    /* Set the next node of the loop ending node
      to fix the loop */
    ptr2->next = NULL;
}
