//naive approach is for every element , go left and count number of elements less than or eqial to curr ele

// optimized is to use stack to keep track of nixt smaller elemnets to left   , we need to maintain the stack in DSC order 
//keep popping till the top of stcak is greater than curr elemnet

void calculateSpan(int price[], int n, int S[]) 
{ 
	// Create a stack and push index of first 
	// element to it 
	stack<int> st; 
	st.push(0); 

	// Span value of first element is always 1 
	S[0] = 1; 

	// Calculate span values for rest of the elements 
	for (int i = 1; i < n; i++) { 
		// Pop elements from stack while stack is not 
		// empty and top of stack is smaller than 
		// price[i] 
		while (!st.empty() && price[st.top()] <= price[i]) 
			st.pop(); 

		// If stack becomes empty, then price[i] is 
		// greater than all elements on left of it, 
		// i.e., price[0], price[1], ..price[i-1]. Else 
		// price[i] is greater than elements after 
		// top of stack 
		S[i] = (st.empty()) ? (i + 1) : (i - st.top()); 

		// Push this element to stack 
		st.push(i); 
	} 
} 


///this is same as above alogo , but modified as per leetcode requirements 

// either you will be given an array  or you will be called price func multiple times 
// in. second case we need to main the indexes as well , so push price and current index to the stack.
// stack should be in DSC order



class StockSpanner {

    stack<pair<int , int>> s ; // {val .index}
    int index = 0 ;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(s.empty()){
            s.push({price , index++});
            return 1;
        } else {
        while(!s.empty() and s.top().first<=price){
            s.pop();
        }
        int span = 0;  
        span = s.empty()?index+1:index-s.top().second;
        s.push({price,index++});
        return span;
      }
  }
};
