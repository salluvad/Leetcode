////////////

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
////////////

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // if its a number push into stack
        //otherwise pop top two elements . do the operation and push
        
        stack<long long int> s;
        
        for(auto it:tokens)
        {
            if(it.size()>1 or isdigit(it[0])){
                s.push(stoi(it));
                continue;
            }
               
            //operator +,=,*,/
            long long int num2 = s.top();
            s.pop();
            long long int num1 = s.top();
            s.pop();
            
            long long int result = 0;
                       
            if(it =="+"){
                result = num1+num2;
            }  else if (it == "-") {
                result = num1 - num2;
            } else if (it == "*") {
                result = num1 * num2;
            } else {
                result = num1 / num2;
            }
            s.push(result);
             
        }
        return s.top();
    }
};
