class Solution {
public:
    //brute force
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int N = temperatures.size();

        vector<int> result(N, 0);

        for(int i = 0; i < N; i++){
            for(int j = i+1; j < N; j++){
                if(temperatures[j] > temperatures[i]){
                    result[i] = j-i;
                    break;
                }
            }
        }
        return result;
        
    }
};
