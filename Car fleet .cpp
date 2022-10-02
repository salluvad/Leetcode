//There are n cars going to the same destination along a one-lane road. The destination is target miles away.

You are given two integer array position and speed, both of length n, 
where position[i] is the position of the ith car and speed[i] is the speed of the ith car (in miles per hour).

A car can never pass another car ahead of it, but it can catch up to it and drive bumper to bumper at the same speed. 
  The faster car will slow down to match the slower car's speed.
  The distance between these two cars is ignored (i.e., they are assumed to have the same position).

A car fleet is some non-empty set of cars driving at the same position and same speed. Note that a single car is also a car fleet.

If a car catches up to a car fleet right at the destination point, it will still be considered as one car fleet.

Return the number of car fleets that will arrive at the destination.

 

Example 1:

Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
Output: 3
Explanation:
The cars starting at 10 (speed 2) and 8 (speed 4) become a fleet, meeting each other at 12.
The car starting at 0 does not catch up to any other car, so it is a fleet by itself.
The cars starting at 5 (speed 1) and 3 (speed 3) become a fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches target.
Note that no other cars meet these fleets before the destination, so the answer is 3.////////////


///////////////
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        /// 
        
      ///  .....A.......B.......c.    .... T , cars A nd B if they are moving at speed greater than C they will collide with C before reaching the target  , so all these will make one fleet 
        // create a vector of pairs of cars pos and speed 
        // sort them based on positin 
        // start form the end (closwr to Target) try finding if latter car reaches before the car closer to the target , it means the later car will catchup with closer car
        //before reaching the target , so they will become a fleet 
        
        // we use a monotonic stack , start form the car closetst to the Target and wal backwards and maintain stack in increasing order of times     // to reach destination 
        
    vector<pair<int,int>> cars;
    
    int n = position.size(); 
    
    for(int i = 0 ; i<n;i++){
        cars.push_back({position[i],speed[i]});
    }
        
    //sort the cars vector based on position 
        
    sort(cars.begin(),cars.end());
        
    // use a stack to kep track of fleets
    
    stack<float> s;
    
    for(int i = n-1 ; i>=0;i--){
        float time = (target-(float)cars[i].first)/(float)cars[i].second;
        if(s.empty()){
           // cout << "pushing time "<< time << endl;
            s.push(time);
        } else {
           /*while(!s.empty() and time >= s.top()) {
               cout << "popping" << s.top() << endl;
                s.pop();
            }
            */
            //cout << "pushing time "<< time << endl;
            if(time > s.top()){         // cars which can reach earlier than top of stack will become part of the fellt for top of stack
                s.push(time);
            }
        }
        
    }
        return s.size();
    }
};




