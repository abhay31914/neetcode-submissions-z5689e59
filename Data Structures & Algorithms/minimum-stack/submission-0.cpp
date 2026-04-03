class MinStack {
public:

    stack<int> minS;
    stack<int> regS;


    MinStack() {
        
    }
    
    void push(int val) {
        regS.push(val);

        if(minS.empty() || minS.top() >= val){
            minS.push(val);
        }
        
    }
    
    void pop() {

        if(regS.top() == minS.top()){
            regS.pop();
            minS.pop();
        }
        else{
            regS.pop();
        }
        
    }
    
    int top() {
        return regS.top();
        
    }
    
    int getMin() {
        return minS.top();
        
    }
};
