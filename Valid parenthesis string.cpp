class Solution {
public:
    bool checkValidString(string s) {
/*
maintain two stacks open and ast
open: stores index where it encountered a '('
ast : stores index where it encountered a '*'

traverse the string:
if '(' is enccountered push it onto the open stack
if '*' is encountered push it onto the ast stack
if ')' is encountered pop 1 element from open stack, but if open stack is empty pop one element from ast stack, but if this is also empty , return FALSE

After traversing all the elements , pop elements from open stack , for corresponding elements in ast stack only if index on top of ast > index on top of open stack (to avoid cases like : "*(" )
if finally open is empty return TRUE, else FALSE
*/
        
        int n = s.length();
        if(n == 0)
            return true;
        if(s[n-1] == '(' || s[0] == ')')
            return false;
        
        stack<int> open,ast;
        for(int i=0;i<n;i++)
          {
              if(s[i] == ')')
              {
                if(open.empty() && ast.empty())
                    return false;
                else if(open.empty()){
                    ast.pop();
                }
                 else
                 {
                     open.pop();
                 }
              }
              else if(s[i] == '*')
              {
                 ast.push(i);
              }
              else{
                 open.push(i);
              }
          }
            while(!open.empty() && !ast.empty()){
                if(open.top() > ast.top())    // to avoid cases like : "*("
                    return false;
                open.pop();
                ast.pop();
            }
            return open.empty();
    }
};
