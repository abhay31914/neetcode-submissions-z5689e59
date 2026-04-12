class FreqStack {

private:

priority_queue<vector<int>> pq;
unordered_map<int, int> freq;
int index = 0;

public:
    FreqStack() {       
    }
    
    void push(int val) {
        freq[val]++;
        pq.push({freq[val], index++, val});
        
    }
    
    int pop() {

        auto top = pq.top();
        pq.pop();
        int val = top[2];
        freq[val]--;

        return val;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */