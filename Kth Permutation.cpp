https://takeuforward.org/data-structure/find-k-th-permutation-sequence/

///resursion brute force

class Solution {
  public:
    //function to generate all possible permutations of a string
    void permutationHelper(string & s, int index, vector < string > & res) {
      if (index == s.size()) {
        res.push_back(s);
        return;
      }
      for (int i = index; i < s.size(); i++) {
        swap(s[i], s[index]);
        permutationHelper(s, index + 1, res);
        swap(s[i], s[index]);
      }
    }

  string getPermutation(int n, int k) {
    string s;
    vector < string > res;
    //create string
    for (int i = 1; i <= n; i++) {
      s.push_back(i + '0');
    }
    permutationHelper(s, 0, res);
    //sort the generated permutations
    sort(res.begin(), res.end());
    //make k 0-based indexed to point to kth sequence
    auto it = res.begin() + (k - 1);
    return *it;
  }
};

/////optimal method

class Solution {
    //https://takeuforward.org/data-structure/find-k-th-permutation-sequence/
public:
    string getPermutation(int n, int k) {
        
// optimal approach is to build the permutaion based on block and swquecne in the block
      int fact = 1;
      vector <int> numbers;
      for (int i = 1; i < n; i++) {
        fact = fact * i;              // factorial of one less
        numbers.push_back(i);
      }
        numbers.push_back(n);    // eg now numbers is {1,2,3,4} , k = 17
        
        string ans = "";
        k = k-1 ; // zero based index 
        
        while(1){
            //first digit
            ans = ans+to_string(numbers[k/fact]);
            //remove that number from the set
            numbers.erase(numbers.begin() + k / fact);
            
            //
            if(numbers.size()==0){
                break;
            }
            
            k = k % fact;
            fact = fact/numbers.size();
             
        }
       
        return ans;
    }
    
};
