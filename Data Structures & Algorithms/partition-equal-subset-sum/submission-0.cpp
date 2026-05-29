class Solution {
public:

    bool isPart(vector<int>& nums, int start, int target){

        if(target < 0 || start >= nums.size())return false;
        if(target == 0) return true;

        return isPart(nums, start+1, target-nums[start]) || isPart(nums, start+1, target);


    }
    bool canPartition(vector<int>& nums) {

        int sum = 0;

        for(int x: nums){
            sum += x;
        }

        if(sum%2) return false;

        int target = sum/2;

        return isPart(nums, 0, target);
        
    }
};
