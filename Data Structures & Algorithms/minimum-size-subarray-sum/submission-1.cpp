class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

    int n = nums.size();
    int i = -1;
    int j = -1;

    int sum = 0;

    int minLen = INT_MAX;

    while(j < n && i <= j){

        if(sum < target){
            j++;
            sum += nums[j];
        }

        else{
            minLen = min(minLen, j-i);           
            i++;
            sum -= nums[i];
        }
    }
    if(i == -1 && j == n) return 0;
    return minLen ;
        
}
};