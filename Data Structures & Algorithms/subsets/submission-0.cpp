class Solution {
public:

    void getSubset(vector<int>& nums, int start, vector<int> &temp, vector<vector<int>> &result, vector<bool> &visited){

        result.push_back(temp);

        for(int i= start; i<nums.size(); i++){

            if(visited[i]) continue;
            visited[i] = true;
            temp.push_back(nums[i]);
            getSubset(nums, i+1, temp, result, visited);
            temp.pop_back();
            visited[i] = false; 
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> result;
        vector<bool> visited(nums.size(), false);
        int st = 0;
        getSubset(nums, st, temp, result, visited);
        return result;
        
    }
};
