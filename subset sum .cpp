Intuition: The main idea is that on every index you have two options either to select the element to add it to your subset(pick) 
  or not select the element at that index and move to the next index(non-pick).

Approach: Traverse through the array and for each index solve for two arrays, one where you pick the element,i.e 
add the element to the sum or don’t pick and move to the next element, recursively, until the base condition. 
  Here when you reach the end of the array is the base condition.
  
class Solution {
  public:
    void subsetSumsHelper(int ind, vector <int> & arr, int n, vector <int> & ans, int sum) {
      if (ind == n) {
        ans.push_back(sum);
        return;
      }
      //element is picked
      subsetSumsHelper(ind + 1, arr, n, ans, sum + arr[ind]);
      //element is not picked
      subsetSumsHelper(ind + 1, arr, n, ans, sum);
    }
  vector <int> subsetSums(vector <int> arr, int n) {
    vector <int> ans;
    subsetSumsHelper(0, arr, n, ans, 0);
    sort(ans.begin(), ans.end());
    return ans;
  }
};
  
