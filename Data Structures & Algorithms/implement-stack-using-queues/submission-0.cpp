class MyStack{
private:
    list<int> l1;
    list<int> l2;

public:
    MyStack(){

    }

    void push(int x){
        l1.push_back(x);
    }

    int pop(){
        int n = l1.size();

        for(int i = 0; i < n-1; i++){
            int x = l1.front();
            l2.push_back(x);
            l1.pop_front();
        }
        int temp = l1.front();
        l1.pop_front();
        swap(l1, l2);

        return temp;
    }

    int top(){
        int n = l1.size();

        for(int i = 0; i < n-1; i++){
            int x = l1.front();
            l2.push_back(x);
            l1.pop_front();
        }
        int temp = l1.front();
        l2.push_back(temp);
        l1.pop_front();
        swap(l1, l2);
        return temp;

    }

    bool empty(){

        return l1.size() == 0;
    }


};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */