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


/////mathematical appraoch
Sum of all elements from 1 to N:

S = N*(N+1)/2 ---- equation 1
And, Sum of squares of all elements from 1 to N:

P = N(N+1)(2N+1)/6. ----- equation 2
Similarly, find the sum of all elements of the array and sum of squares of all elements of the array respectively.

s1 = Sum of all elements of the array. —– equation 3
P1 = Sum of squares of all elements of the array. ——– equation 4
Now, if we subtract the sum of all elements of array from sum of all elements from 1 to N, that should give us the value for (X – Y).

Therefore,

(X-Y) = s – s1 = s’

Similarily,

X^2 – Y^2 = P – P1 = P’

or, (X + Y)(X – Y) = P’

or, (X + Y)*s’ = P’

or, X + Y = P’/s’

Great,

we have the two equations we needed:

(X – Y) = s’

(X + Y) = P’/s’

We can use the two equations to solve and find values for X and Y respectively.

>>>>>>>>

vector<int>missing_repeated_number(const vector<int> &A) {
    long long int len = A.size();

    long long int S = (len * (len+1) ) /2;
    long long int P = (len * (len +1) *(2*len +1) )/6;
    long long int missingNumber=0, repeating=0;
     
    for(int i=0;i<A.size(); i++){
       S -= (long long int)A[i];
       P -= (long long int)A[i]*(long long int)A[i];
    }
     
    missingNumber = (S + P/S)/2;

    repeating = missingNumber - S;

    vector <int> ans;

    ans.push_back(repeating);
    ans.push_back(missingNumber);

    return ans;
}
