class Solution {
public:
    struct compare {
        bool operator() (ListNode* a , ListNode*b){
            return a->val>b->val ;
        }
        
    } ;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        
        
        //push first element of each list 
        for (int i = 0; i < k; i++)
             if (lists[i] != NULL)
                pq.push(lists[i]);
        
        //
          if (pq.empty())
              return NULL;
        
      //
        
      struct ListNode *dummy = new ListNode(0);
      struct ListNode *last = dummy;
        
        while(!pq.empty()){
            ListNode* curr= pq.top();
            pq.pop();
            
            last->next = curr;
            last = last->next;
            
            if(curr->next!=NULL)
               pq.push(curr->next);
            
        }
        return dummy->next;
    }
};
