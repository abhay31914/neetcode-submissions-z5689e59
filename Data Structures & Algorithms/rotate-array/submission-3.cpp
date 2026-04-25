class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        //optimal
        int n = nums.size();

        k = k%n;

        int i = 0;
        int j = n-1;
        while(i < j){
            swap(nums[i], nums[j]);
            i++;
            j--;
        }

        int l1 = 0;
        int l2 = k-1;
        while(l1 < l2){
            swap(nums[l1], nums[l2]);
            l1++;
            l2--;
        }

        int r1 = k;
        int r2 = n-1;
        while(r1 < r2){
            swap(nums[r1], nums[r2]);
            r1++;
            r2--;
        }   
    }
};