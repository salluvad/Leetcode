// method 1 count based 
//method 2 two pointer , both fo them are o(m+n)


//method 1
Get the count of the nodes in the first list, let the count be c1.
Get the count of the nodes in the second list, let the count be c2.
Get the difference of counts d = abs(c1 – c2)
Now traverse the bigger list from the first node to d nodes so that from here onwards both the lists have an equal no of nodes
Then we can traverse both lists in parallel till we come across a common node. (Note that getting a common node is done by comparing the address of the nodes)
int getIntesectionNode(Node* head1, Node* head2)
{
 
    // Count the number of nodes in
    // both the linked list
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d;
 
    // If first is greater
    if (c1 > c2) {
        d = c1 - c2;
        return _getIntesectionNode(d, head1, head2);
    }
    else {
        d = c2 - c1;
        return _getIntesectionNode(d, head2, head1);
    }
}
 
/* function to get the intersection point of two linked
lists head1 and head2 where head1 has d more nodes than
head2 */
int _getIntesectionNode(int d, Node* head1, Node* head2)
{
    // Stand at the starting of the bigger list
    Node* current1 = head1;
    Node* current2 = head2;
 
    // Move the pointer forward
    for (int i = 0; i < d; i++) {
        if (current1 == NULL) {
            return -1;
        }
        current1 = current1->next;
    }
 
    // Move both pointers of both list till they
    // intersect with each other
    while (current1 != NULL && current2 != NULL) {
        if (current1 == current2)
            return current1->data;
 
        // Move both the pointers forward
        current1 = current1->next;
        current2 = current2->next;
    }
 
    return -1;
}
 
/* Takes head pointer of the linked list and
returns the count of nodes in the list */
int getCount(Node* head)
{
    Node* current = head;
 
    // Counter to store count of nodes
    int count = 0;
 
    // Iterate till NULL
    while (current != NULL) {
 
        // Increase the counter
        count++;
 
        // Move the Node ahead
        current = current->next;
    }
 
    return count;
}
 



//method 2
Using Two pointers : 

Initialize two pointers ptr1 and ptr2  at head1 and  head2.
Traverse through the lists, one node at a time.
When ptr1 reaches the end of a list, then redirect it to head2.
similarly, when ptr2 reaches the end of a list, redirect it to the head1.
Once both of them go through reassigning, they will be equidistant from 
 the collision point
If at any node ptr1 meets ptr2, then it is the intersection node.
After the second iteration if there is no intersection node it returns NULL.
  
  
  Node* intersectPoint(Node* head1, Node* head2)
{
    // Maintaining two pointers ptr1 and ptr2
    // at the head of A and B,
    Node* ptr1 = head1;
    Node* ptr2 = head2;
 
    // If any one of head is NULL i.e
    // no Intersection Point
    if (ptr1 == NULL || ptr2 == NULL)
        return NULL;
 
    // Traverse through the lists until they
    // reach Intersection node
    while (ptr1 != ptr2) {
 
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
 
        // If at any node ptr1 meets ptr2, then it is
        // intersection node.Return intersection node.
 
        if (ptr1 == ptr2)
            return ptr1;
        /* Once both of them go through reassigning,
        they will be equidistant from the collision point.*/
 
        // When ptr1 reaches the end of a list, then
        // reassign it to the head2.
        if (ptr1 == NULL)
            ptr1 = head2;
        // When ptr2 reaches the end of a list, then
        // redirect it to the head1.
        if (ptr2 == NULL)
            ptr2 = head1;
    }
    r
