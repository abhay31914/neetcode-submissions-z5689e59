class MyCircularQueue {
private:
    
    int* buff;
    int head;
    int tail;
    int cap;
    int curSize = 0;

public:

    MyCircularQueue(int k): cap(k), head(0), tail(-1){

        buff = new int[cap];
        
    }
    
    bool enQueue(int value) {

        if(!isFull()){
            tail = (tail+1)%cap;

            buff[tail] = value;
            curSize++;

            return true;
        }
        return false;
        
    }
    
    bool deQueue() {

        if(!isEmpty()){
            
            head = (head+1)%cap;
            curSize--;

            return true;
        }
        return false;
        
    }
    
    int Front() {

        if(!isEmpty()) return buff[head];
        return -1;
        
    }
    
    int Rear() {

        if(!isEmpty()) return buff[tail];
        return -1;
        
    }
    
    bool isEmpty() {

        return curSize == 0;
        
    }
    
    bool isFull() {

        return curSize == cap;
        
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