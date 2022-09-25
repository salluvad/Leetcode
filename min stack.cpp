class MinStack {
    // there are two methods
    // 1/use a pair {val, min} to insert into the stack 
    // 2. use a modified value toinsert if val is less tha min striver.  https://takeuforward.org/data-structure/implement-min-stack-o2n-and-on-space-complexity/
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


//// method 2 , where we optimeze the extra space 
// we insert modified value if the curr ele is smaller than min and while pop we need to bring back the min to previous min

class MinStack {
  stack < long long > st;
  long long mini;
  public:
    /** initialize your data structure here. */
    MinStack() {
      while (st.empty() == false) st.pop();
      mini = INT_MAX;
    }

  void push(int value) {
    long long val = Long.valuevalue;
    if (st.empty()) {
      mini = val;
      st.push(val);
    } else {
      if (val < mini) {
        st.push(2 *val*1LL - mini);
        mini = val;
      } else {
        st.push(val);
      }
    }
  }

  void pop() {
    if (st.empty()) return;
    long long el = st.top();
    st.pop();

    if (el < mini) {
      mini = 2 * mini - el;
    }
  }

  int top() {
    if (st.empty()) return -1;

    long long el = st.top();
    if (el < mini) return mini;
    return el;
  }

  int getMin() {
    return mini;
  }


