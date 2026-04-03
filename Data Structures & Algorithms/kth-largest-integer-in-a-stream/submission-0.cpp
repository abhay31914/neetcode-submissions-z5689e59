class KthLargest {
private:
    int n;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    
    KthLargest(int k, vector<int>& nums): n(k) {

        for(int x: nums){
            pq.push(x);

            if(pq.size() > n){
                pq.pop();
            }
        }
        
    }
    
    int add(int val) {
        pq.push(val);

        if(pq.size() > n){
            pq.pop();
        }
        return pq.top();
        
    }
};
