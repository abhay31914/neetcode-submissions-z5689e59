class Solution {
public:

    void getSubset(vector<int>& nums, int start, vector<int> &temp, vector<vector<int>> &result){

        result.push_back(temp);

        for(int i= start; i<nums.size(); i++){
            temp.push_back(nums[i]);
            getSubset(nums, i+1, temp, result);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> result;
        getSubset(nums, 0, temp, result);
        return result;
        
    }
};
