class Solution {
public:
    void solve(vector<int> &nums, vector<int> &temp, vector<vector<int>> &results, vector<bool> &visited){

    if(temp.size() == nums.size()){
        results.push_back(temp);
        return;
    }

    for(int i = 0; i< nums.size(); i++){
        if(visited[i]) continue;

        if(i > 0 && nums[i-1] == nums[i] && !visited[i-1]) continue;
        visited[i] = true;
        temp.push_back(nums[i]);
        solve(nums, temp, results, visited);
        temp.pop_back();
        visited[i] = false;
    }

}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    int n = nums.size();
    vector<bool> visited(n);
    vector<int> temp;
    vector<vector<int>> results;
    sort(nums.begin(), nums.end());

    solve(nums, temp, results, visited);

    return results;
        
}
};