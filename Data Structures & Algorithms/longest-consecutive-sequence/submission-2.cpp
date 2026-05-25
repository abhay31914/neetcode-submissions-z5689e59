class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

    unordered_set<int> map;

    for(int x: nums){
        map.insert(x);
    }

    int max_count = 0;

    for(int i = 0; i< nums.size(); i++){

        int x = nums[i];

        if(map.find(x-1) == map.end()){
            int count = 0;

            while(map.find(x) != map.end()){
                count++;
                x++;
            }
            max_count = max(max_count, count);
        }
    }
    return max_count;   
}

};
