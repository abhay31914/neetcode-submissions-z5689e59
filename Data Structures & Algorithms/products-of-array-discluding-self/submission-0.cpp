class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        vector<int> right(n), left(n);

        right[0] = nums[0];
        left[n-1] = nums[n-1];

        for(int i = 1; i< n; i++){
            right[i] = right[i-1]*nums[i];
            left[n-i-1] = left[n-i]*nums[n-i-1];
        }

        nums[0] = left[1];
        nums[n-1] = right[n-2];

        for(int i=1; i< n-1; i++){
            nums[i] = right[i-1]*left[i+1];
        }
        return nums;

    }
};
