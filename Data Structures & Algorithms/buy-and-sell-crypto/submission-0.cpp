class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        int minP = 100;
        int maxP = 0;

        int result = 0;

        for(int i = 0; i < n; i++){

            if(prices[i] <= minP){
                minP = prices[i];
                maxP = prices[i];
            }
            else if(prices[i] > maxP){
                maxP = prices[i];
            }
            result = max(result, maxP-minP);
            
            

        }
        return result;
        
    }
};
