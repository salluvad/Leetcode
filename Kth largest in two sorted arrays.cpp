We can part it in such a way that our kth element will be at the end of the left half array. 
  Let’s make some observations. The left portion of the array is made of some elements of both array1 and array2. 
  We can see that all elements of the right half of the array are always larger than the left ones. 
  So, with help of binary search, we will divide arrays into partitions with keeping k elements in the left half. 
  We have to keep in mind that l1 <= r2 and l2 <= r1. Why so? This ensures that left-half elements are always lesser than right elements



int kthelement(int arr1[], int arr2[], int m, int n, int k) {
    if(m > n) {
        return kthelement(arr2, arr1, n, m, k); 
    }
        
    int low = max(0,k-m), high = min(k,n);   /// edge case , if K is < m , how many max elements we can pick from arr1 ? its K elements 
                                              /// second edge case , if K is > n . how many elements we can pick from arr2 ? minimum n elements 
        
    while(low <= high) {
        int cut1 = (low + high) >> 1; 
        int cut2 = k - cut1; 
        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1]; 
        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
        int r1 = cut1 == n ? INT_MAX : arr1[cut1]; 
        int r2 = cut2 == m ? INT_MAX : arr2[cut2]; 
            
        if(l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }
        else if (l1 > r2) {
            high = cut1 - 1;
        }
        else {
            low = cut1 + 1; 
        }
    }
    return 1; 
}
