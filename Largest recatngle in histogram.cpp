class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // we use leftsmall and right small arrays 
        // for every indec , area is max of rightsmall[i]-leftsmall[i]+1 * height[i]
        
        // we use stack technique like Nest greater and next smaller problem to fill these arrays 
        
        int n = heights.size();
        
        stack<int> s;
        
        int leftsmall[n];
        int rightsmall[n];
        
        //fill left small , start from 0
        
        for(int i = 0 ; i<n ; i++){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop(); 
            }
            if(s.empty()){
                leftsmall[i] = 0;
            } else {
                leftsmall[i] = s.top()+1;
            }
            
            s.push(i);
        }
        
        // clear the stakc for using next time 
        while (!s.empty())
           s.pop();
        
        //right smaller 
        for(int i = n-1 ; i>=0 ; --i){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop(); 
            }
            if(s.empty()){
                rightsmall[i] = n-1;
            } else {
                rightsmall[i] = s.top()-1;
            }
            
            s.push(i);
        }
        
        int max_Area = 0;
        
        for(int i = 0 ; i<n;i++) {
            max_Area = max(max_Area,heights[i]*(rightsmall[i]-leftsmall[i]+1));
        }
        
        return max_Area;
    }
};
