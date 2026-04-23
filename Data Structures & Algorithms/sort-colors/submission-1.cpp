class Solution {
public:
    void sortColors(vector<int>& nums) {

    int i = -1;
    int j = nums.size();

    int k = 0;

    while(k < j){

        if(nums[k] == 0){
            i += 1;
            swap(nums[i], nums[k]);
        }

        else if(nums[k] == 2){
            j -= 1;
            swap(nums[k], nums[j]);
        }

        if( nums[k] == 1 || i == k) k += 1;
    }       
}
};