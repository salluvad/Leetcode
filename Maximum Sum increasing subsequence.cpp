// same as LIS 
// diff is in second condition , arr[i]>arr[j] and MIS[i]>arr[i]+MIS[j]


class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    if(n==0){
	        return 0;
	    }
	    if(n ==1){
	        return arr[0];
	    }
	    vector<int> MIS(n,0);
	    MIS[0] = arr[0] ;
	    int max = 0;
	    for(int i = 1;i<n;i++){
	        MIS[i]= arr[i];
	        for(int j = 0 ; j<i;j++){
	            if(arr[i]>arr[j] and MIS[i]<arr[i]+MIS[j]){
	                MIS[i]= MIS[j]+arr[i];
	                
	            }
	        }
	    }
	    for(int i = 0 ;i<n;i++){
	        if(MIS[i]>max){
	           max = MIS[i];
	       }
	    }
	    return max;
	}  
};
