#include <mutex>

class MyCircularQueue {
private:
    vector<int> q;
    int cap;
    mutex m;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        cap = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        m.lock();
        if (q.size() < cap) {
            q.push_back(value);
            m.unlock();
            return true;
        }
        
        m.unlock();        
        return false;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        m.lock();
        if (q.size() > 0) {
            q.erase(q.begin(), q.begin()+1);
            m.unlock();
            return true;            
        }
        
        m.unlock();
        return false;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        return q.size() > 0 ? q[0] : -1;        
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        return q.size() > 0 ? q[q.size()-1] : -1;        
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return q.size() == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return q.size() == cap;
    }
};
