class MedianFinder {
private:
    // idea here is to find the middle element or elements in constant time 
    // we have to use balanced binary tree or heap
    // we didvide the incoming stream into two halves , left half is manintained by max heal
    // right half is maintained by min heap
    priority_queue<int> max_heap;
    priority_queue<int , std::vector<int>,std::greater<int>> min_heap;
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int i) {
      /*  int lsize=max_heap.size();
        int rsize= min_heap.size();
        
        //base case if both are empty
        if(lsize==0){
            max_heap.push(num);
        } else if(lsize==rsize){   // both are same size
            if(num<min_heap.top()){
                max_heap.push(num);
            } else { 
                int temp = min_heap.top();
                min_heap.pop();
                min_heap.push(num);
                max_heap.push(temp);                
            }
        }
            else {
                if(min_heap.size()==0){
                    if(num>max_heap.top()){
                        min_heap.push(num);
                    }
                    else {
                    int temp = max_heap.top();
                    max_heap.pop();
                    min_heap.push(temp);
                    max_heap.push(num);
                    }
                } else if(num>=min_heap.top()){
                        min_heap.push(num);
                    } else {
                    if(num<max_heap.top()){
                        int temp = max_heap.top();
                        max_heap.pop();
                        min_heap.push(temp);
                        max_heap.push(num);
                    }
                    }
                }
                */
int lsize = max_heap.size();
int rsize = min_heap.size();

//base case if lsize=0 )
if(lsize==0)
   max_heap.push(i);
else if(lsize == rsize)
      {
       if(i<min_heap.top())
          max_heap.push(i);
       else {
          int temp = min_heap.top();
	  min_heap.pop();
	  min_heap.push(i);
	  max_heap.push(temp);
       }

      }
else {
      if(min_heap.size()==0) {
         if(i>max_heap.top()) {
           min_heap.push(i);
         }
         else {
          int temp = max_heap.top();
          max_heap.pop();
	  max_heap.push(i);
          min_heap.push(temp);
         }
      }
      else if(i>=min_heap.top())
		min_heap.push(i);
            else {
             if(i<max_heap.top()){
	       int temp = max_heap.top();
		max_heap.pop();
		max_heap.push(i);
		min_heap.push(temp);
              } else min_heap.push(i);

            }

            }
        
    }
    
    double findMedian() {
  if(max_heap.size() == min_heap.size()) return max_heap.empty()?0:( (max_heap.top()+min_heap.top())/2.0);
        else return (max_heap.size() > min_heap.size())? max_heap.top():min_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
