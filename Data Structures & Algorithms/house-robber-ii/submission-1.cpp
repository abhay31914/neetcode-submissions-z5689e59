class Solution {
public:

    int maxVal(vector<int>& nums, int st, int end){

        int n = end-st+1;

        vector<int> dp(n+2, 0);

        for(int i = 2; i< n+2; i++){
            dp[i] = max(nums[st+i-2] + dp[i-2], dp[i-1]);
        }

        return dp[n+1];
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) return nums[0];


        return max(nums[0] + maxVal(nums, 2, n-2), maxVal(nums, 1, n-1));
        
    }
};
