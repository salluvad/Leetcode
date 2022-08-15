//Naive appraoch >sort and traverse the array , if arr[i] == arr[i+1] . then that element is repeating 
//ifarr[i+1] != 1+arr[i] , then missing is arr[i]+1;

//appraoch 2 . we use an auxillary array 
int repeating,missing;
        bool present[N+1] = {false};  //Checks which numbers are present
        for(int i=0;i<N;++i)
        {
            if(present[arr[i]]==true)
                repeating = arr[i];
            present[arr[i]] = true;
        }

//second traverse for missing num    >>>> numbers start form 1,2,3,4,.... so index starts at 1
  for(int i=1;i<=N;++i)
        {
            if(present[i]==false)
            {
                missing = i;
                break;
            }
        }
