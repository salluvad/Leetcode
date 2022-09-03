stack<int> sortStack(stack<int> &input)
{
    stack<int> tmpStack;
 
    while (!input.empty())
    {
     int temp = input.top();
     input.pop();
     
     while(!tmpStack.empty() and tmpStack.top()>temp){
       input.push(tmpStack.top());
       tmpStack.pop();
    }
      tmpStack.push(temp);
   }
    return tmpStack;
}
