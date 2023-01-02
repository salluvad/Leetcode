//https://leetcode.com/problems/baseball-game/

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int ans =0;
        for(auto it:operations){
           if(it == "+"){   // add last two values in stack 
               int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                
                st.push(y);
                st.push(x);
                st.push(x+y);
        }
            else if(it == "C"){  // invalidate
                st.pop();
            }
            else if(it == "D"){
                st.push(2*st.top());
            }
            else{
                int x = stoi(it);  // convert to int and push 
                st.push(x);
            }
        }
        
        //return the sum of all ele in stack 
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
    
};
