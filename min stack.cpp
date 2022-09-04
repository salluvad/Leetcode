class MinStack {
    // there are two methods
    // 1/use a pair {val, min} to insert into the stack 
    // 2. use a modified value toinsert if val is less tha min striver
stack<pair<int,int>> s;

int min;
public:
    MinStack() {
      min = INT_MAX  ;
    }
    
    void push(int val) {
        if(s.empty()){
            min = val;
            s.push({val,min});
        } else {
              min = std::min(s.top().second,val);
              s.push({val,min});
            }
        }
    
    
    void pop() {
       s.pop();
        
    }
    
    int top() {
      return  s.top().first;
   
    }
    
    int getMin() {
         return  s.top().second;
    }
};
