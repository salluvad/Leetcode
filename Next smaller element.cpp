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
