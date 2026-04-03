class Solution {
public:
    int cost_recur(vector<int>& cost, int n, vector<int>& dp){
    if(n < 2) return 0;

    if(dp[n] != -1) return dp[n];

    return dp[n] = min(cost[n-1] + cost_recur(cost, n-1, dp), cost[n-2]+ cost_recur(cost, n-2, dp));
}

int minCostClimbingStairs(vector<int>& cost){
    int n = cost.size();
    vector<int> dp(n+1, -1);

    return cost_recur(cost, n, dp);

}
};
