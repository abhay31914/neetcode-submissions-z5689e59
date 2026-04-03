class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();
        std::cout<<n<<std::endl;

        int i = 0;
        int j = 1;

        while(j< n){
            if(nums[i] != nums[j]){
                nums[++i] = nums[j];
            }
            j++;
        }
        std::cout << i << std::endl;
        return (i+1);
        
    }
};