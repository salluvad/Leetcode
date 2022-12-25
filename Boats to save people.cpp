You are given an array people where people[i] is the weight of the ith person, 
and an infinite number of boats where each boat can carry a maximum weight of limit. 
  Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.


class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // it can be solved using Binary search if boat can carry any number of people , nust like shiiping 
        //porblem 
        
        // greedy apparoach , just like max volume problem 
        // try to pair heaviest person with lightest person 
        
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;
        
        int ans = 0 ;
        
        while(i<=j){
            ans++;
            if(people[i] + people[j] <= limit){
                i++;
            }
            j--;
        }
        
        return ans;
    }
};
