// greedy approach 
Approach: We will keep a pointer at the end of the array i. Now while(V >= coins[i]) we will reduce V by coins[i] and add it to the ans array.

We will also ignore the coins which are greater than V and the coins which are less than V. We consider them and reduce the value of V by coins[I].
  
  #include<bits/stdc++.h>


using namespace std;
int main() {
  int V = 49;
  vector < int > ans;
  int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
  int n = 9;
  for (int i = n - 1; i >= 0; i--) {
    while (V >= coins[i]) {
      V -= coins[i];
      ans.push_back(coins[i]);
    }
  }
  cout<<"The minimum number of coins is "<<ans.size()<<endl;
  cout<<"The coins are "<<endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
