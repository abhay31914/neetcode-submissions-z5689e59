class Solution {
public:
    void solve(vector<vector<int>> &result, vector<int> &temp, int start, int n, int k){
    if(temp.size() == k){
        result.push_back(temp);
        return;
        
    };

    for(int i = start; i < n+1 ; i++){
        temp.push_back(i);
        solve(result, temp, i+1, n, k);

        temp.pop_back();
    }
    return;
}

vector<vector<int>> combine(int n, int k){

    int start = 1;
    vector<vector<int>> result;
    vector<int> temp;
    
    solve(result, temp, start, n, k);

    return result;
}
};