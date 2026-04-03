class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int curSum = 0;
        int result = 0;

        unordered_map<int, int> map;

        map[0] = 1;

        for(int num: nums){

            curSum += num;
            int diff = curSum -k;
            result += map[diff];
            map[curSum]++;
        }
    return result;
        
    }
};