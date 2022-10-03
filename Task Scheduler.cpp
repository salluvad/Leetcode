///

Given a characters array tasks, representing the tasks a CPU needs to do, 
where each letter represents a different task. Tasks could be done in any order. 
  Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), 
that is that there must be at least n units of time between any two same tasks.

Return the least number of units of times that the CPU will take to finish all the given tasks.

 

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: 
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.


////



class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //create a freq map
        unordered_map<char,int> mp;
        for(char task:tasks){
            mp[task]++;
           // cout << "key" << (task) << "val" <<  mp[task] << endl;
        }
        
        //create a max heap and push the elements into it as per freq
        priority_queue<pair<int,char>> pq;
        
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        
        //create a queue  to keep track of processed tasks which can be scheduled later after cool down time
        queue<pair<pair<int,char>,int>> q;
        int time = 0;
        while(!pq.empty() or ! q.empty()){
            time++;
            //get the top ele from max heap
            if(!pq.empty()){
                auto temp = pq.top();
                pq.pop();
                
               // cout << "char " << temp.second << endl;
                //reduce the freq count of that task;
                temp.first--;

                if(temp.first>0){
                    q.push({{temp.first,temp.second},time+n}) ;
                }
           }
            if(!q.empty()){
                if(q.front().second == time){
                    pq.push(q.front().first);
                    q.pop();
                }
            }
        }
        return time;
    }
};
