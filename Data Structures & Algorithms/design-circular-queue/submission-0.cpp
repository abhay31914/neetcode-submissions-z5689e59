class MyCircularQueue {
private:
    vector<int> cq;
    int head;
    int tail;
    int capacity;
public:
    MyCircularQueue(int k): cq(k, -1), head(0), tail(-1), capacity(k){
        
    }
    
    bool enQueue(int value) {

        if(!isFull()){
            tail++;
            cq[tail % capacity] = value;
            return true;
        }
        return false;
        
    }
    
    bool deQueue() {

        if(!isEmpty()){
            cq[head % capacity] = -1;
            head ++;
            return true;
        }
        return false;       
    }
    
    int Front() {
        if(!isEmpty()) return cq[head % capacity];
        return -1;
        
    }
    
    int Rear() {
        if(!isEmpty()) return cq[tail % capacity];
        return -1;

        
    }
    
    bool isEmpty() {
        return tail < head;
        
    }
    
    bool isFull() {

        return tail-head+1 == capacity;   
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */