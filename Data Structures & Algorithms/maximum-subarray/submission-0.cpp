class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int Snow = -1000;
        int Smax = -1000;

        for(int ele: nums){
             Snow = max(Snow+ ele, ele);
             Smax = max(Smax, Snow);

        }
        return Smax;

    }
};
