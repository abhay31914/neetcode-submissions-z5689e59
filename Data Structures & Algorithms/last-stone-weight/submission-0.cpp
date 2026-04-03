class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(int st: stones){
            pq.push(st);
        }

        while(pq.size() > 1){
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();
            
            int diff = s1 - s2;
            if(diff > 0) pq.push(diff);
        }

        if(!pq.empty()) return pq.top();

        return 0;
        
    }
};
