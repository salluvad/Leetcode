// return number of mini internvals need to remmoved to make it non overlapping set 

https://leetcode.com/problems/non-overlapping-intervals/
////

 bool cmp(vector<int>&a, vector<int>&b) {
        if( a[0]==b[0]){
            return a[1]<b[1];
        } else return a[0]<b[0] ;
 }       
    
class Solution {

public:
   
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // greedy way of finding the min removals 
        // sort them based on start value 
        
        int res=0;
        
        sort(intervals.begin(),intervals.end(),cmp);
        
        for(auto it : intervals){
           // cout << "[" <<it[0] << " " << it[1] << "]"<< endl  ;
        }
        
        auto temp  = intervals[0];
        
        int prevEnd = temp[1];
        
        for(int i = 1 ; i< intervals.size();i++){
            if(intervals[i][0]>=prevEnd){
                prevEnd=intervals[i][1] ;
            } else {
                //cout << intervals[i][0] <<  "  " << intervals[i][1] << endl;
                res++;
                prevEnd = min(intervals[i][1],prevEnd );     // remove the interval which is ending later 
            }
        }
            
       return res; 
    }
};
