class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //two pointer 
        int l = 0 ;
        int r = 1 ;
        int max_profit = 0 ;
        //left = buy
        //right = sell
        while(r < prices.size()){
            if(prices[r]-prices[l] < 0){ // -ve profit
                //move the buy and sell dates 
                l = r;
                r++;
                
            } else {
                max_profit = max(max_profit,prices[r]-prices[l]);
                r++;
            }
        }
        return max_profit;
    }
};
