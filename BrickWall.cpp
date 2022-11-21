/*

There is a rectangular brick wall in front of you with n rows of bricks. 
The ith row has some number of bricks each of the same height (i.e., one unit) but they can be of different widths. 
The total width of each row is the same.

Draw a vertical line from the top to the bottom and cross the least bricks. If your line goes through the edge of a brick, 
then the brick is not considered as crossed. You cannot draw a line just along one of the two vertical edges of the wall, 
in which case the line will obviously cross no bricks.

Given the 2D array wall that contains the information about the wall, 
return the minimum number of crossed bricks after drawing such a vertical line.

*/


class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        //Neetcode 
        //main idea ia to find out at which position we have maximum number of gaps 
        // we maintain a hashmap of position and # of gaps at that pos.
        // traverse through each row and fill the hashmap 
        
        //after filling the hashmap , find the max value of gaps and our answer is rows-max_gaps (which gives min cuts)
        unordered_map<int,int> gaps; //<positio , gaps >  // 
        int max_gap = 0;
        for(auto row:wall){
            int prev_pos = 0;
            for(int i=0;i<row.size()-1;i++){
                gaps[prev_pos+row[i]]++;
                cout << "pos " << prev_pos+row[i] << " val " << gaps[prev_pos+row[i]]<< endl;
                max_gap = max(max_gap, gaps[prev_pos+row[i]]);
                prev_pos= prev_pos+row[i];
            }
        }
        cout << "max_gap" << max_gap << endl;
        return wall.size()-max_gap;
    }
};
