class Solution { //brute force
public:
    int firstMissingPositive(vector<int>& nums) {

        int minNum = 1;

        unordered_set<int> s;

        for(int x: nums){
            s.insert(x);

        } 

        for(int i = 0; i <= nums.size(); i++){
            if(s.find(minNum) == s.end()) return minNum;
            minNum++;
        } 
        return 1;      
    }
};