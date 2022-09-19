class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    int n = s.size();
		    vector<string> ans;
		    for(int num = 0 ; num<pow(2,n);num++){
		        string temp = "";
		        for(int i = 0 ; i<n;i++){
		            if(num & (1<<i)){
		                temp+=s[i];
		            }
		        }
		        ans.push_back(temp);
		    }
		     sort(ans.begin(),ans.end());
		     return ans;
		}
};
