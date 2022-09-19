We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.
  https://leetcode.com/problems/maximum-profit-in-job-scheduling/


class Solution {
public:
    //DP array
    int dp[50001]; // see conditions in Question
     int memo[50001];
    int findmaxProfit(vector<vector<int>>jobs,vector<int>startTime) {
       int len = startTime.size();
            //start loop from the end 
            for(int pos = len-1;pos>=0;pos--){
                int curr_profit = 0;

                int next_index = lower_bound(startTime.begin(),startTime.end(),jobs[pos][1])-startTime.begin();

                if(next_index == len){
                        curr_profit = jobs[pos][2];       
                } else {
                        curr_profit = jobs[pos][2]+dp[next_index];
                }

                if(pos==len-1){
                    dp[pos]=curr_profit;
                } else {
                    dp[pos] = max(curr_profit,dp[pos+1]);
                }
            
        }
        return dp[0];
    }
    
    int findmax_recur_memo(vector<vector<int>>& jobs, vector<int>& start, int n, int position){
        //base case 
        if(position == n){
            return 0 ; // no more profit
        }
        
        //memo array
        if(memo[position]!=-1){
            return memo[position];
        }
        
        //two case skip and no skip
        //lets calc the next index in case we took the job 
        int nextIndex = lower_bound(start.begin(), start.end(), jobs[position][1])-start.begin();
        
        int maxProfit = max(findmax_recur_memo(jobs, start, n, position + 1),findmax_recur_memo(jobs, start, n, nextIndex)+jobs[position][2]);
        
        return memo[position] = maxProfit;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        //DP +bottom up
        vector<vector<int>> jobs;
        
        for(int i = 0 ; i<profit.size();i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        //sort
        sort(jobs.begin(),jobs.end());
        
        //create a sperate array for start times , we use this for finding the next 
        //non-overlapping interval
        
        for(int i = 0 ; i<profit.size();i++){
            startTime[i]=jobs[i][0];
        }
        
         memset(memo, -1, sizeof(memo));
        return findmax_recur_memo(jobs,startTime,profit.size(),0); // recur+memo
       // return findmaxProfit(jobs,startTime); // DP
    }
};
