class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> result;

        int n = nums.size();

        sort(nums.begin(), nums.end());

        int iPrev = INT_MAX;

        for(int i = 0; i < n-2; i++){

            int j = i+1;
            int k = n-1;

            if(nums[i] == iPrev) continue;
            int jPrev = INT_MAX;
            int kPrev = INT_MAX;

            while(j < k){
                int sum = nums[i]+ nums[j] + nums[k];

                if(sum == 0){
                    if(jPrev != nums[j] && kPrev != nums[k]) result.push_back({nums[i], nums[j], nums[k]});
                    jPrev = nums[j];
                    kPrev = nums[k];
                    j++;
                    k--;
                }

                else if(sum > 0){
                    k--;
                }
                else{
                    j++;
                }
            }
        iPrev = nums[i];   
        }

        return result;
        
    }
};
