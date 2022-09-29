class Solution {
public:
    vector<int> countBits(int n) {
        // brute force is run a loop from i to n and count ones ad add it to ans vector 
        // that takes n logn time 
        
        vector<int> ans;
		/*
		// iterating fromt 0 to n
        for(int i = 0; i<=n; i++)
        {
			// sum is initialised as 0
            int sum = 0;
            int num = i;
			// while num not equals zero
            while(num != 0)
            {
				// we have to count 1's in binary representation of i, therefore % 2
                sum += num%2;
                num = num/2;
            }
			// add sum to ans vector
            ans.push_back(sum);
        }
		// return 
        return ans;
        */
        // for o(n) tC , we need to compute results from previous computations 
        
        // number of ones in zero is 0 , thas our base case
        // if n os even , the number of 1's is same as in n/2 
        // if n is odd , they are 1+ same as n/2 
        
        vector<int> memo(n+1,0);
        memo[0] = 0;
        for(int i = 1 ; i<=n; i++){
            memo[i] = memo[i/2]+(i%2);
        }
        
        return memo;
        
    }
};
