class Solution {
public:
    vector<int> majorityElement(vector<int>& nums){

    int size = nums.size();

    unordered_map<int, int> map;

    vector<int> result;

    for(int ele: nums){

        map[ele]++;

        if(map[ele] == size/3 +1) result.push_back(ele);

    }

    return result;

}
};