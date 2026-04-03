class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int cur_ele = nums[0];
        int prev_ele;
        int cur_count = 1;
        int prev_count = 0;

        for(int i = 0; i< nums.size(); i++){
            if(nums[i] == cur_ele) cur_count++;
            else if(nums[i] == prev_ele) {
                swap(cur_ele, prev_ele);
                swap(cur_count, prev_count);
                cur_count++;
            }
            else{
                if(cur_count > prev_count){
                    prev_ele = cur_ele;
                    prev_count = cur_count;
                }
                cur_ele = nums[i];
                cur_count = 1;
            }
        }
        return prev_count > cur_count ? prev_ele: cur_ele;
    }
};