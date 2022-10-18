/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
 // Two ways of doing it , one is to use hash table to keep the mapping of old and cloned nodes , so we can refer the nodes in o(1) time 
        // other method is by manupulating pointers  , tricky but o(1) space , no need to maintain hash table 
       // https://www.youtube.com/watch?v=OvpKeraoxW0

///using hashmap
Node* copyRandomList(Node* head) {
    unordered_map<Node*,Node*> hashMap;
    Node* temp = head;
//first iteration for inserting deep nodes of every node in the hashmap.
    while(temp != NULL) {
        Node* newNode = new Node(temp->val);
        hashMap[temp] = newNode;
        temp = temp->next;
    }
    Node* t = head;
//second iteration for linking next and random pointer as given question.
    while(t != NULL) {
        Node* node = hashMap[t];
        node->next = (t->next != NULL) ? hashMap[t->next]:NULL;
        node->random = (t->random != NULL) ? hashMap[t->random]:NULL;
        t = t->next;
    }
    return hashMap[head];
}
>>>>>>>>>>>


O(1)

>>>>>>>>>>
class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Two ways of doing it , one is to use hash table to keep the mapping of old and cloned nodes , so we can refer the nodes in o(1) time 
        // other method is by manupulating pointers  , tricky but o(1) space , no need to maintain hash table 
       // https://www.youtube.com/watch?v=OvpKeraoxW0
        
  /*      OLD1    OLD2   OLD3  OLD4   OLD5 ->NULL
         |     /. |   /   |  /. |   /. |   /
         NEW1     NEW2    NEW3   NEW4  NEW5
         
*/
        
        while(head == NULL){
            return NULL;
        }
        
        Node* curr = head ;
        // create copy nodes and link them with old nodes's next pointers 
        while(curr){
            Node* temp = curr->next;
            Node* new_node= new Node(curr->val,temp,NULL);   // this constructor sets the next of the node to temp
            curr->next = new_node;
            curr = new_node->next;
        }
        
        //now second pass , assign the random pointers 
        curr = head ;
        while(curr){
             curr->next->random = curr->random ?curr->random->next:NULL;
             curr = curr->next->next;            
        }
        
        //third pass  , reconstruct the original list
        Node* new_head = head->next;
        curr = head ;
        while(curr){
            Node* next_node = curr->next;
            curr->next = next_node->next;
            curr = curr->next;
            next_node->next = curr?curr->next:NULL ;
        }
        return new_head;
    }
};
