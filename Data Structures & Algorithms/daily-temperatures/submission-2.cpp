class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<int> st; // pair: {temp, index}

        for (int i = 0; i < temperatures.size(); i++) {
            int t = temperatures[i];
           while(!st.empty() && t > temperatures[st.top()]){
            int idx = st.top();
            st.pop();
            res[idx] = i-idx;
           }
           st.push(i);
        }
        return res;
        
    }
};
