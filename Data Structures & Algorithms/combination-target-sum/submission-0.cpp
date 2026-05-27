class Solution {
public:

void checkSum(vector<int>& nums, set<vector<int>>& st, vector<int>& temp, int& sum , int target, int n){

    if(sum == target){

       vector<int> ptemp = temp;

        sort(ptemp.begin(), ptemp.end());

        st.insert(ptemp);
        return;        
    }

    if(sum > target) return;


    for(int i = 0; i < n; i++){

        sum += nums[i];
        temp.push_back(nums[i]);
        checkSum(nums, st, temp, sum, target, n);

        sum -= nums[i];
        temp.pop_back();
    }
}


vector<vector<int>> combinationSum(vector<int>& nums, int target) {

    vector<vector<int>> result;
    vector<int> temp;

    set<vector<int>> st;



    int sum = 0;
    int n = nums.size();

    checkSum(nums, st, temp, sum, target, n);

    for(auto x: st){
        result.push_back(x);
    }

    return result;

        
}
};
