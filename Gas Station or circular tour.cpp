/////
https://leetcode.com/problems/gas-station/

////


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // greedy apprach , try from each starting point and see if we can make a circular tour 
        
        // sanity check 
        //if total gas is < total cost . we can not make a circular tour 
        int total_gas = 0;
        int total_cost = 0 ;
        
        for(int i = 0; i<gas.size();i++){
            total_gas+=gas[i];
            total_cost+=cost[i];
        }
        
        if(total_gas<total_cost){
            return -1;
        }
        
       // lets keep track of balance gas  as we move 
        int total = 0 ;
        int start = 0 ; 
        
       for(int i = 0; i<gas.size();i++){
           total += gas[i]-cost[i];
                                        
           if(total<0){
               total = 0;
               start = i+1;
           }
       }
        return start ;
    }
};
