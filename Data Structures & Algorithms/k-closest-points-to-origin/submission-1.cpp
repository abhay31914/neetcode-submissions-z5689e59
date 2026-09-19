class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int, vector<int>>> pq;

        for(auto& v: points){
            int dist = v[0]*v[0] + v[1]*v[1];

            pq.push({dist, v});

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<vector<int>> result;

        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
        
    }
};
