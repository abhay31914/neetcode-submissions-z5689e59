class Solution {
public:
    //using tracker variable prev & cur
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int, int>> cPair;
        int n = position.size();
        for(int i = 0; i< n; i++){
            cPair.push_back({position[i], speed[i]});
        }
        sort(cPair.rbegin(), cPair.rend());

        stack<double> st;

        for(auto& px: cPair){
            double time = (double)(target-px.first)/px.second;

            if(!st.empty() && st.top() >= time) continue;

            st.push(time);           
        }

    return st.size();    
    }
};
