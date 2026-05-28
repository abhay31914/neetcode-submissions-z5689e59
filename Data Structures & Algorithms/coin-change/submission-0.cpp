class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount+1, 0);

        for(int i = 1; i <= amount; i++){
            int min_count = INT_MAX;

            for(auto x: coins){

                if(x > i) continue;
                if(dp[i - x] == -1) continue;

                min_count = min(min_count, 1 + dp[i-x]);
            }
            dp[i] = min_count != INT_MAX ? min_count: -1;
        }

        return dp[amount];    
    }
};
