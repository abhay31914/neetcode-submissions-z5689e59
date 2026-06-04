class MyCircularQueue {
private:
    vector<int> cQ;
    int head = 0;
    int tail = -1;
    int cap;
    int size = 0;

public:
    MyCircularQueue(int k): cQ(k, -1), cap(k){
        
    }
    
    bool enQueue(int value) {

        if(!isFull()){
            tail = (tail+1) % cap;
            cQ[tail] = value;
            size++;
            return true;
        }
        return false;
        
    }
    
    bool deQueue() {
        if(!isEmpty()){
            cQ[head] = -1;
            head = (head+1) % cap;
            size--;
            return true;

        }
        return false;
        
    }
    
    int Front() {
        if(!isEmpty()) return cQ[head];
        return -1;
        
    }
    
    int Rear() {

        if(!isEmpty()) return cQ[tail];
        return -1;
        
    }
    
    bool isEmpty() {
        return size == 0;
        
    }
    
    bool isFull() {

        return size == cap;
        
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