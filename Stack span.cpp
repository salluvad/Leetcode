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
