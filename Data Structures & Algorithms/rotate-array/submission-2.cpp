class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        //extra-space
        int n = nums.size();

        k = k%n;

        vector<int> arr;

        for(int i = n-k; i < n; i++){
            arr.push_back(nums[i]);
        }

        for(int i= n-1; i >= k; i--){
            nums[i] = nums[i-k];
        }

        for(int i = 0; i<k; i++){
            nums[i] = arr[i];
        }
    }
};