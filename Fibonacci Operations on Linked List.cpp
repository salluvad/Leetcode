//https://www.geeksforgeeks.org/various-operations-on-fibonacci-nodes-in-a-singly-linked-list/

Algo : main step
Traverse through the entire singly linked list and obtain the maximum value in the list
Now, build a hash table containing all the Fibonacci nodes less than or equal to the maximum value in the singly linked list.
  
  
set<int> hashmap;\
  
void deleteNode(Node** head_ref, Node* del).  // API to delete a node 
{
    // Base case
    struct Node* temp = *head_ref;
 
    if (*head_ref == NULL || del == NULL)
        return;
 
    // If the node to be deleted is
    // the head node
    if (*head_ref == del){
        *head_ref = del->next;
          return;
    }
 
    // Traverse list till not found
    // delete node
    while (temp->next != del) {
        temp = temp->next;
    }
 
    // Copy address of node
    temp->next = del->next;
 
 
    return;
}
// Function that returns the largest element
// from the linked list.
int largestElement(struct Node* head_ref)
{
    // Declare a max variable and
    // initialize it with INT_MIN value.
    // INT_MIN is integer type and
    // its value is -32767 or less.
    int max = INT_MIN;
 
    Node* head = head_ref;
 
    // Loop to iterate the linked list
    while (head != NULL) {
 
        // If max is less than head->data then
        // assign value of head->data to max
        // otherwise node point to next node.
        if (max < head->data)
            max = head->data;
 
        head = head->next;
    }
    return max;
}


// Function to create a hash table
// to check Fibonacci nodes
void createHash(int maxElement)
{
    // Insert the first two
    // elements in the hash
    int prev = 0, curr = 1;
    hashmap.insert(prev);
    hashmap.insert(curr);
 
    // Add the elements until the max element
    // by using the previous two numbers
    while (curr <= maxElement) {
        int temp = curr + prev;
        hashmap.insert(temp);
        prev = curr;
        curr = temp;
    }
}
///

int printFibonacci(Node** head_ref)
{
 
    int count = 0;
    Node* ptr = *head_ref;
 
    cout << "Fibonacci nodes = ";
 
    while (ptr != NULL) {
 
        // If current node is Fibonacci
        if (hashmap.find(ptr->data)
            != hashmap.end()) {
 
            // Update count
            cout << ptr->data << " ";
        }
 
        ptr = ptr->next;
    }
 
    cout << endl;
    return 0;
}

// Function to find maximum and minimum
// fibonacci nodes in a linked list
void minmaxFibonacciNodes(Node** head_ref)
{
    // Find the largest node value
    // in Singly Linked List
    int maxEle = largestElement(*head_ref);
 
    // Creating a set containing
    // all the Fibonacci nodes
    // upto the maximum data value
    // in the Singly Linked List
    // set<int> hash;
    // createHash(hash, maxEle);
 
    int minimum = INT_MAX;
    int maximum = INT_MIN;
    Node* ptr = *head_ref;
 
    while (ptr != NULL) {
 
        // If current node is fibonacci
        if (hashmap.find(ptr->data)
            != hashmap.end()) {
 
            // Update minimum
            minimum
                = min(minimum, ptr->data);
 
            // Update maximum
            maximum
                = max(maximum, ptr->data);
        }
        ptr = ptr->next;
    }
 
    cout << "Minimum Fibonacci node: "
         << minimum << endl;
    cout << "Maximum Fibonacci node: "
         << maximum << endl;
}
