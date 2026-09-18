class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> pq;

        for(int x: stones){
            pq.push(x);
        }

        while(true){

            if(pq.size() == 1) break;

            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();

            int x = s1 -s2;

            pq.push(x);

        }
        return pq.top();
        
    }
};
