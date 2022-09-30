Leetcode 11
  You are given an integer array height of length n. 
  There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

////////


class Solution {
public:
    int maxArea(vector<int>& height) {
        //two pointer method
        //pair up each element with bigger element on each iteration
        int i = 0;
        int j = height.size()-1;
        long max_area = 0 ;
        long area = 0 ;
        while(i<j){
            area = (j-i)*min(height[i],height[j]);
            if(max_area < area) {
                max_area = area;
            }
            if(height[i]<height[j]){
                i++;
            } else j--;
            
        }
        return max_area;
    }
};
