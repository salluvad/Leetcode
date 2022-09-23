// brute force is to use a set , set keep sonly unique elemenst 
//after insertng all elemnets in set , pop and insert back in the array
//size of set is the number of unique elements

int removeDuplicates(int arr[], int n) {
  set < int > set;
  for (int i = 0; i < n; i++) {
    set.insert(arr[i]);
  }
  int k = set.size();
  int j = 0;
  for (int x: set) {
    arr[j++] = x;
  }
  return k;
}
///////
method 2 , two pointer approach
fix i and keep moving j till you find a diff element than arr[i] ,
then inc i and replace a[i] with a[j].
 int removeDuplicates(int arr[], int n)
{
  int i = 0;
  for (int j = 1; j < n; j++) {
    if (arr[i] != arr[j]) {
      i++;
      arr[i] = arr[j];
    }
  }
  return i + 1;
}
////////
  
////////<<<<<<<same as above>>>>>>>>>>>///////////
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n==0 || n==1)
            return n;
        
        int j = 0 ; // index for unique elements
        
        for (int i = 0 ; i<n-1; i++){
            if(nums[i]!=nums[i+1]){
                nums[j]=nums[i];
                j++;
            }
        }
        nums[j++] = nums[n-1];
        
        return j;
        
    }
};
