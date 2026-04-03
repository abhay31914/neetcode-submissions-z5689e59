class StockSpanner{
    private:
    stack<pair<int, int>> s;

    public:
    StockSpanner(){}

    int next(int price){

        pair<int, int> ele = {price, 1};

         
        while(!s.empty() && s.top().first <= price){
            
            pair<int, int> temp = s.top();
            s.pop();
            ele.second += temp.second;

        }
        
        s.push(ele);
        return ele.second;
    }

};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */