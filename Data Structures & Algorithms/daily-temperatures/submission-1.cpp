class Solution {
public:
    //brute force
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int N = temperatures.size();

        vector<int> result(N, 0);

        stack<pair<int, int>> st;

        for(int i = N-1; i >= 0; i--){

            while(!st.empty() && st.top().first <= temperatures[i]){
                st.pop();
            }
            if(!st.empty()){
                result[i] = st.top().second - i;
            }
            st.push({temperatures[i], i});
            
        }
        return result;
        
    }
};
