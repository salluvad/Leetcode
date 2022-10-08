/////

Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize,
and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, 
return true if she can rearrange the cards, or false otherwise.

 

Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]


/////




class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
         int k= groupSize;
        // we need to divide the array inyo k groups of consecutive numbers 
        //first we check if it can be divided into k groups
        int n = hand.size();
        if(n%k !=0){
            return false ;
        }
        
        //keep a count of available numbers 
        
        map<int , int> hm;
        for(auto it:hand){
            hm[it]++;
        }
        
       
        // we an create min heap to find the key in constant time or you can just walk through hash map keys and find the min element 
        priority_queue<int ,vector<int>,greater<int>> pq;
        
        for(auto it:hm){
            pq.push(it.first);   // pushing all the keys 
        }
        
        // now go through the hash map find the min elemnet and decrement its count in hm 
        // if key count is zero , we can pop the val 
        
        int count = 0 ;
        //loop k times 
        //this is not needed , but we can push answers 
        vector<vector<int>> ans;
        
        while(!pq.empty()){
            int first = pq.top();
            
            for(int i = first;i<first+k;i++){
                //check if the key is in hash map 
               
                if(hm.find(i)==hm.end()){
                    cout << "1"<< i << endl ; 
                    return false ;
                } else {
                    //decrment the count 
                     hm[i]--;
                    
                    if(hm[i]==0){
                        //pop from min heap , we will pop only if its top elemnet , there are other cases where we need to pop elements which are no top , in that case we return false like  eg 1,1,2,3, , when we need to pop 2 , it will not be the top element
                        if(i==pq.top()){  
                            pq.pop();
                        } else {
                           
                            return false ;
                        }
                    }
                }
            }
            
        }
        return true;
    }
};
