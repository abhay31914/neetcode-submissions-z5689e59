class Solution {
public:
    void solve(vector<int> &nums, vector<vector<int>> &result, vector<int> &temp, unordered_set<int> &idx){
    if(temp.size() == nums.size()){
        result.push_back(temp);
        return;
        
    };

    for(int j = 0; j < nums.size(); j++){
        if(idx.find(j) == idx.end()){
            temp.push_back(nums[j]);
            idx.insert(j);
            solve(nums, result, temp, idx);
            temp.pop_back();
            idx.erase(j);
        }
    }
    return;
}

vector<vector<int>> permute(vector<int>& nums){
    vector<vector<int>> result;
    vector<int> temp;
    unordered_set<int> idx;

    solve(nums, result, temp, idx);

    return result;
}
};
