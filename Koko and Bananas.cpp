class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // we need to create a binary search space . we can apply binary search to any monotonic search space 
        // we need to find left and right boundaries 
        // in this eaxmple .each pile has certain number of bananas 
        // so min num of bananas koko can east is 1 
        // and max num of bananas koko can eat is max(num in a pile)    
        // in this example of [3,4,5,7,11] , min numof banas is 1 and max num of banaas is 11 
        // so our search space is [1.....11] 
        // now we have to find the K num of bananas Koko can eat with in H hours 
        // need to minimize the K
        
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        int result = 0;
        while(l<=r){
            int k = (l+r)/2;
            long long hours = 0 ;
            
            //lets find out with this K value how many hours we need to eat all the bananas
            for(int pile:piles){
               // hours += pile/k +(pile%k!=0) ;
                hours += ceil(1.0 * pile/k);// piles%k!=0 >>>> basicaly the remaining banaas need another hours to eat ,
            }
            
            if(hours <=h){
                result = k;
                //we need to minimize the K value . so move the right tofind even smaller sol
                r = k-1;
            }else {
                l = k+1;
            }
            
        }
        
        return result;
    }
};
