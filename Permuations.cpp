// we have both ways , recursion and back tracking 
// in recursion we use a temp sapce to create a intermediate result and map/array to keep trak of taken numbers  , extra space 0(n) and time is 0(n!*N)

// in back tracking we dont need that extra space to keep track of used numbers , we swap with all other indexes  space 0(1) and time is 0(n!*N)

////method 1 recursion 

 void recurPermute(vector <int> & ds, vector <int> & nums, vector <vector<int>> & ans, int freq[]) {
      if (ds.size() == nums.size()) {.  //base case if ds size is same as array size
        ans.push_back(ds);
        return;
      }
      for (int i = 0; i < nums.size(); i++) {
        if (!freq[i]) {
          ds.push_back(nums[i]);
          freq[i] = 1;
          recurPermute(ds, nums, ans, freq);
          freq[i] = 0;
          ds.pop_back();
        }
      }
    }

vector<vector<int >> permute(vector <int> & nums) {
      vector <vector<int>> ans;
      vector < int > ds;  // to keep intermeduate result
      int freq[nums.size()];  // to keep track of used chars/numbers
      for (int i = 0; i < nums.size(); i++) freq[i] = 0;   // set all freq to zero
      recurPermute(ds, nums, ans, freq);
      return ans;
}



/// method 2

class Solution {
  private:
    void recurPermute(int index, vector <int> & nums, vector <vector<int>> & ans) {
      if (index == nums.size()) {
        ans.push_back(nums);
        return;
      }
      for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);
        recurPermute(index + 1, nums, ans);
        swap(nums[index], nums[i]);
      }
    }
  public:
    vector <vector<int>> permute(vector < int > & nums) {
      vector <vector<int>> ans;
      recurPermute(0, nums, ans);
      return ans;
    }
};
