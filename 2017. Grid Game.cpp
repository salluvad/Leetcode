
//https://leetcode.com/problems/grid-game/


class Solution {
public:
    #define ll long long
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        // we calc prefix sum  for each row
        ll pre1[n+1];
        ll pre2[n+1];
        
        pre1[0] = grid[0][0] , pre2[0] = grid[1][0];
        
        for(int i=1;i<n;i++)
        {
            pre1[i] = pre1[i-1] + grid[0][i];
            pre2[i] = pre2[i-1] + grid[1][i];
            
        }
        
        ll res = LONG_MAX;
        
        //we need to find the dip point /transition point of robot 1 from row 0 to row1 which yields max result for robot1 , means robot 2 will have minimum score
        for(int i=0;i<n;i++)
        {
			/*we have 2 options
			 1. to take the values in row 0 after the turning point
			 2. to take the values in row 1 before turning point
            */
            ll op1 = pre1[n-1] - pre1[i];
            ll op2 = i==0 ? 0 : pre2[i-1];
            
			
			/*the 2nd robot wants to take the best of two options avalable
			  so we take max of op1 and op2
			  but the first robot wants to minimize its score,
			  hence we take min
            */
            res = min(res,max(op1,op2));
        }
        return res;
    }
    
};
