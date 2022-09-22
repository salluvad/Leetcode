
////////
Using Two pointers : 

Initialize two pointers ptr1 and ptr2  at head1 and  head2.
Traverse through the lists, one node at a time.
When ptr1 reaches the end of a list, then redirect it to head2.
similarly, when ptr2 reaches the end of a list, redirect it to the head1.
Once both of them go through reassigning, they will be equidistant from 
 the collision point
If at any node ptr1 meets ptr2, then it is the intersection node.
After the second iteration if there is no intersection node it returns NULL.


///////



class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA; 
        ListNode* p2 = headB; 
        
      if(p1==NULL || p2==NULL){
          return NULL;
      }
       while(p1!=p2){
           p1=p1->next;
           p2=p2->next;
           
           if(p1==p2){
               return p1;
           }
           if(p1==NULL){
               p1=headB;
           }
           if(p2==NULL){
               p2=headA;
           }
       }
        return p1;
    }
};
