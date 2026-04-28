class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

    int l = 0;
    int r = 0;
    int n = nums.size();

    int minLen = INT_MAX;
    int sumFar = 0;

    while(r < n){

        sumFar += nums[r];

        while(sumFar >= target & l <= r){
            minLen = min(minLen, r-l+1);
            sumFar -= nums[l];
            l++;
        }
        r++;
    }

    return minLen <= n ? minLen : 0;
        
}
};