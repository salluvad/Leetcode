//////// next smaller element to left//////

vector<int> Solution::prevSmaller(vector<int> &nums) {
      int n = nums.size();
        vector<int> nge(n,-1);
        stack<int> s;
        
        for(int i = nums.size()-1; i >= 0; i--)
            s.push(nums[i]);
        
       /* for(int i = nums.size()-1; i >= 0; i--){
            while(!s.empty() && s.top() <= nums[i])
                s.pop();
            
            if(s.empty()) nge[i] = -1;
            else nge[i] = s.top();
            
            s.push(nums[i]);
        }*/
        
        for(int i = n-1 ; i>=0;--i){
            
                //remove all the smaller elements in stack
                while(!s.empty() and s.top()>=nums[i]){
                    s.pop();
                }
                //add the curr element
       
                if(!s.empty()) nge[i]=s.top();
                              
            
                s.push(nums[i]);
                           
        }
        
        return nge;
    }
}




///////////////////////////////

void printNSE(int arr[], int n)
{
	stack<int> s;
   vector<int> nse(n,-1);
   
    for(int i = n-1 ; i>=0;--i){
     while(!s.empty() and s.top()>=arr[i]){
      s.pop();
     }
      if(!s.empty()) nse[i] = s.top();
      
      if(s.empty() or (!s.empty()and arr[i]<s.top())) s.push(arr[i]);
      
    }

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ---> " << nse[i] << endl;
	}
}

// Driver program to test above functions
int main()
{
	int arr[] = { 11, 13, 21, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printNSE(arr, n);
	return 0;
}
