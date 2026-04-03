class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

    int x = 0;
    int n = nums.size();

    for(int i = 0; i< n; i++){
        if(nums[i] != val){
            if(i != x) swap(nums[i], nums[x]);
            x++;
        }
    }
    return x;
}
};