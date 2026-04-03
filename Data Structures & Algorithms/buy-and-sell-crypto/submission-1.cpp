class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        int minP = 100;
        int maxP = 0;

        int result = 0;

        for(int i = 0; i < n; i++){

            minP = min(minP, prices[i]);
            result = max(result, prices[i]-minP);
        }
        return result;
        
    }
};
