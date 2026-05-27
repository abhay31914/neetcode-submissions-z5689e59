class Solution {
public:

void checkSum2(vector<int>& nums, vector<vector<int>>& result, vector<int>& temp, int target, int idx){

    if(target == 0){
        result.push_back(temp);
        return;
    }

    if(target < 0 || idx >= nums.size()) return;

    temp.push_back(nums[idx]);
    checkSum2(nums, result, temp, target-nums[idx], idx);
    temp.pop_back();

    checkSum2(nums, result, temp, target, idx+1);
}


vector<vector<int>> combinationSum(vector<int>& nums, int target) {

    vector<vector<int>> result;
    vector<int> temp;

    checkSum2(nums, result, temp, target, 0);

    return result;

        
}
};
