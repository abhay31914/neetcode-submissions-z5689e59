class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, vector<int>> map;

        for(int i= nums.size() -1; i >= 0; i--){
            map[nums[i]].push_back(i);
        }

        for(int i = 0; i< nums.size(); i++){

            map[nums[i]].pop_back();

            if(map[target - nums[i]].size() >= 1){
                return {i, map[target - nums[i]][0]};
            }    
        }
        
    }
};
